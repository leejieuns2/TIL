# Chapter 6. Process Synchronization

### 💡 데이터의 접근

![](../../image/data_access.png)

<br>

### 💡 Race Condition (경쟁 상태)

![](../../image/race_condition.png)

- 중복 접근이 발생하는 경우 결과 값에 문제가 발생해 원치 않은 결과를 얻게 될 수 있음.
  
<br>

#### OS 에서 Race Condition이 발생하는 경우
1. Kernel 수행 중 인터럽트 발생 (interrupt handler vs kernel)
   
    <br>
    
   ![](../../image/race_condition_1.png)
   
    <br>
   
    - 중요한 변수값을 kernel이 처리하는 경우 interrupt 처리를 disable 시켜서 kernel이 수행하는 프로세스가 종료된 후 interrupt를 처리하는 방식으로  문제를 주로 해결함.
    
   
2. Process가 System Call을 발생시켜 Kernel mode로 수행 중인데 문맥교환(Context Switch)이 발생하는 경우

    <br>
   
    ![](../../image/race_condition_2.png)
    
    <br>

    - 해결책 : 커널 모드에서 수행 중일 때는 CPU를 preempt하지 않음. 커널 모드에서 사용자 모드로 돌아갈 때 preempt
    

3. Multiprocessor에서 shared memory 내의 kernel data

    <br>

   ![](../../image/race_condition_3.png)

    <br>

   - lock을 걸어서 다른 어느 누구도 현재 사용하고 있는 data에 접근하지 못하도록 하는 해결법.
   - 프로세스가 끝난 후에는 lock을 해제하여 다른 프로세스도 사용할 수 있도록 처리함.

<br>

### 💡 Process Synchronization 문제
- 공유 데이터(shared data)의 동시 접근(concurrent access)은 데이터의 불일치 문제(inconsistency)를 발생시킬 수 있다.
- 일관성(Consistency) 유지를 위해서는 협력 프로세스(cooperating procee)간의 실행 순서(orderly execution)를 정의해주는 메커니즘이 필요하다.
- Race Condition
   - 여러 프로세스들이 동시에 공유 데이터를 접근하는 상황
   - 데이터의 최종 연산 결과는 마지막에 그 데이터를 다룬 프로세스에 따라 달라짐.
- race condition을 막기 위해서는 공존하 프로세스(concurrent process)가 동기화(Synchronize)되어야 한다.

<br>

### 💡 The Critical-Section Problem
- n개의 프로세스가 공유 데이터를 동시에 사용하기를 원하는 경우
- 각 프로세스의 code segment에는 공유 데이터를 접근하는 코드인 critical section이 존재
- problem
   - 하나의 프로세스가 critical section에 있을 때 다른 모든 프로세스는 critical section에 들어갈 수 없어야 한다.
   
<br>

----

<br>

# Chapter 6. Process Synchronization (2)

<br>

### 💡 Initial Attempts to solve problem
- 두 개의 프로세스가 있다고 가정. P0, P1
- 프로세스들의 일반적인 구조

   ```shell
      do {
        entry section
        critical section
        exit section
        reminder section
      } while(1);
   ```

- 프로세스들은 수행의 동기화(Synchronize)를 위해 몇몇 변수를 공유할 수 있다. -> Synchronization variable

<br>

### 💡 프로그램적 해결법의 충족 조건

1. Mutual Exclusion (상호 배제)
- 프로세스 Pi가 critical section 부분을 수행 중이면 다른 모든 프로세스들은 그들의 critical section에 들어가면 안 된다.
- 프로세스는 서로 배타적이어야 한다.
   
2. Progress (진행)
- 아무도 critical section에 있지 않은 상태에서 critical section에 들어가고자 하는 프로세스가 있으면 critical section에 들어가게 해 주어야 한다.
- 당연한 이야기지만 만족하지 못하는 경우가 있기 때문에 중요한 충족 조건임.

3. Bounded Waiting (유한 대기)
- 프로세스가 critical section에 들어가려고 요청한 후부터 그 요청이 허용할 때까지 다른 프로세스들이 critical section에 들어가는 횟수에 한계가 있어야 한다.
- starvation(기아 상태)이 발생하지 않는 것을 의미함.

< 가정 >
- 모든 프로세스의 수행 속도는 0보다 크다
- 프로세스들 간의 상대적인 수행 속도는 가정하지 않는다.

<br>

### 💡 Synchronization Algorithm

#### Method 1
- Synchronization variable
  `int turn;` -> 어떤 프로세스의 차례인지를 나타내는 변수값으로 사용
  `initially turn = 0;`   
  => P1 can enter its critical section if(turn == i)

- Process P0
  ```shell
  do {
    while (turn != 0);  # My turn?
    critical section
    turn = 1;           # Now it's your turn
    remainder section
  } while(1);
  ```

- Process P1
  ```shell
  do {
    while (turn != 1);  # My turn?
    critical section
    turn = 0;           # Now it's your turn
    remainder section
  } while(1);
  ```
  
- turn 변수값을 파악 후 while문의 조건이 true면 무한루프를 돌면서 대기. 나머지 프로세스는 critical section에 진입.
  나머지 프로세스가 critical section에서 빠져나오면 turn 변수값의 값이 변경되므로 대기하던 프로세스는 while문에서 빠져나와 critical section에 진입 가능하게 됨.
- Satisfies mutual exclusion, but not progress (과잉 양보)
- 반드시 한번씩 교대로 들어가야만 함. (swap-turn) turn 값을 내 값으로 바꿔줘야만 내가 critical section에 들어갈 수 있음.
- 만약 특정 프로세스가 더 빈번히 critical section에 들어가야 한다면 
  turn 변수값을 변경하지 않고 계속 critical section을 점유하게 될 수도 있으므로 이 알고리즘은 완벽한 알고리즘은 아님.

<br>

#### Method 2
- Synchronization variable
  `boolean flag[2];`
  `initially flag[all] = false;`  => No one is in CS (critical section)
- Pi ready to enter its critical section if (flag[i] == true)

- Process Pi
  ```shell
  do {
    flag[i] = true;   # Pretend I am in (프로세스에 들어가고 싶다는 의사 표시)
    while (flag[j]);  # Is It also in? than wait (프로세스가 이미 점유되고 있는지 확인)
    critical section
    flag[i] = false;  # I'm out now
    remainder section
  } while(1);
  ```
  
- Satisfies mutual exclusion, but not progress requirement.
- 둘 다 2행까지 수행 후 끊임 없이 양보하는 상황 발생 가능

<br>

#### Method 3 (Peterson's Algorithm)
- Combined synchronization variables of algorithms 1 and 2
- Process Pi
  ```shell
  do {
    flag[i] = true;   # My intention is to enter ...
    turn = j;         # set to its turn
    while (flag[j] && turn == j); 
    critical section
    flag[i] = false;  # I'm out now
    remainder section
  } while(1);
  ``` 

- Meets all three requirements. solves the critical section problem for two processes.
- Busy waiting (= spin lock, 계속 CPU와 memory를 사용하면서 waiting)

<br>

### 💡 Synchronization Hardware
- 하드웨어적으로 Test & Modify를 동시에 수행할 수 있도록 지원하는 경우 앞의 문제는 간단히 해결됨.
- Mutual Exclusion wit Test & set 
  - Synchronization variable
    `boolean lock = false'`
    
  ```shell
  do {
    while (Test_and_Set(lock)); 
    critical section
    lock = false;      
    remainder section
  } while(1);
  ```
  
- 하드웨어적으로 읽는 작업과 값을 세팅하는 작업을 동시에 할 수 있다는 가정 하에 만들어진 해결 방법

<br>

### 💡 Semaphores (세마포) 

<br>

### 💡 

<br>

### 💡 