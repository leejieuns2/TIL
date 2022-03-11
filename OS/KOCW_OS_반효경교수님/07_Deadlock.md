# Chapter 7. Deadlock (교착상태)

### 💡 The Deadlock Problem
- Deadlock : 일련의 프로세스들이 서로가 가진 자원을 기다리며 block된 상태
    - Example 1.
        - 시스템에 2개의 tape drive가 있다.
        - 프로세스 P1, P2 각각이 하나의 tape drive를 보유한 채 다른 하나를 기다리고 있다.
    - Example 2.
        - Binary Semaphores A and B   
          |   P1  	|   P2   |
          |:---:    |:---:   |
          | P(A); 	| P(B);  |
          | P(B); 	| P(A);  |
          
- Resource 
    - 하드웨어, 소프트웨어 등을 포함하는 개념   
    ex) I/O device, CPU cycle, Memory space, semaphore 등
    - 프로세스가 자원을 사용하는 절차
        - Request --> Allocate --> Use --> Release

<br>

### 💡 Deadlock 발생의 4가지 조건
- 이 조건들을 충족하지 않으면 교착상태는 발생하지 않음.

1. Mutual Exclusion (상호 배제)
   - 매 순간 하나의 프로세스만이 자원을 사용할 수 있음.
    
2. No preemption (비선점)
   - 프로세스는 자원을 스스로 내어놓을 뿐 강제로 빼앗기지 않음
    
3. Hold and Wait (보유 대기)
   - 자원을 가진 프로세스가 다른 자원을 기다릴 때 보유 자원을 놓지 않고 계속 가지고 있음.
    
4. Circular wait (순환 대기)
   - 자원을 기다리는 프로세스 간에 사이클이 형성되어야 함.
   - 프로세스 P0...Pn이 존재한다는 가정에서   
        P0은 P1이 가진 자원을 기다림   
        P1은 P2이 가진 자원을 기다림   
        Pn-1은 Pn이 가진 자원을 기다림   
        Pn은 P0이 가진 자원을 기다림   

<br>
