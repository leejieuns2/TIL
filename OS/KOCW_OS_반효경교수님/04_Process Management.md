# Chapter 4. Process Management

### 💡 프로세스 생성 (Process Creation)

- 부모 프로세스(Parent Process)가 자식 프로세스(Children Process)를 생성한다.
  (프로세스가 또 다른 프로세스를 만드는 구조. **복제 생성**)
- 프로세스의 트리(계층 구조)가 형성된다.
- 프로세스는 자원을 필요로 한다. 이 때, **자원은 운영체제(OS)로부터 받거나 부모와 공유**한다.
- 자원의 공유
    - 부모와 자식이 모든 자원을 공유하는 모델
    - 일부를 공유하는 모델 (모든 자원을 공유하는 것보다 더 효율적임) ex) Linux
    - 전혀 공유하지 않는 모델
- 수행 (Execution)
    - 부모와 자식은 공존하며 수행되는 모델
    - 자식이 종료(terminate)될 때까지 부모가 기다리는(wait = blocked) 모델
- 주소 공간(Address space)
    - 자식은 부모의 공간(문맥)을 복사함 (binary and OS data) -> Code, Data, Stack 전부 복사하는 것.
    - PC(Program Counter) Register도 그대로 복사함.
    - 자식은 그 공간에 새로운 프로그램을 올림
    
    > Copy-on-Write(COW)
    - Write가 발생했을 때 Copy가 실행되는 것.
    - 내용이 변경되었을 경우에만 Copy를 진행하고 그 전까지는 공유만 하는 것을 의미함.
    

- 유닉스의 예
    - fork() 시스템 콜이 새로운 프로세스를 생성
        - 부모를 그대로 복사 (OS data except PID + binary)
        - 주소 공간 할당
        - 시스템 콜이 호출되는 것이므로 OS가 해당 작업(프로세스 생성)을 대신 수행하는 개념으로 이해해야 함.
    - fork 다음에 이어지는 exec() 시스템 콜을 통해 새로운 프로그램을 메모리에 올림.움
    
< 프로세스의 생성과정 정리 >
1. 부모 프로세스의 복제 (부모 프로세스가 자식 프로세스를 생성) --> `fork()`
2. 새로운 프로세스를 주소 공간에 덮어씌움. --> `exec()`

<br>

### 💡 프로세스 종료 (Process Termination)
- 프로세스가 마지막 명령을 수행한 후 운영체제에게 이를 알려줌 (Exit)
    - 자식이 부모에게 output data를 보냄 (via wait)
    - 프로세스의 각종 자원들이 운영체제에게 반납됨.
    - 프로세스에서는 무조건 자식 프로세스가 먼저 종료되고 부모 프로세스가 종료되어야 함.
    
- 부모 프로세스가 자식의 수행을 종료시킴 (abort - 강제 종료)
    - 자식이 할당 자원의 한계치를 넘어섬
    - 자식에게 할당된 태스크가 더 이상 필요하지 않음
    - 부모가 종료(exit)하는 경우
        - 운영체제는 부모 프로세스가 종료하는 경우 자식이 더 이상 수행되도록 두지 않는다.
        - 강제 종료 시에도 자식 프로세스가 먼저 종료된 후 부모 프로세스가 종료되기 때문에 단계적인 종료가 발생함.

<br>

### 💡 `fork()` System Call
- A process is created by the `fork()` system call
    - creates a new address space that is a duplicate of the caller
    
```shell
    int main() {
        int pid;
        pid = fork(); 
        # fork() 함수가 실행되면 하나의 프로세스가 더 생성된다고 이해하는 것이 쉬움.
        if(pid == 0) {
            printf("\nHello, I am child!\n");
        } eise if (pid > 0) {
            printf("\nHello, I am parent!\n");
        }
    }
```
<br>

### 💡 `exec()` System Call
- A process can execute a different program by the `exec()` system call.
    - replaces the memory image of the caller with a new program.

```shell
    int main() {
        int pid;
        pid = fork(); 
        # fork() 함수가 실행되면 하나의 프로세스가 더 생성된다고 이해하는 것이 쉬움.
        if(pid == 0) {  
            # this is child
            printf("\nHello, I am child! Now I'll run date \n");
            execlp("/bin/date", "/bin/date", (char *) 0);
        } eise if (pid > 0) {   
            # this is parent
            printf("\nHello, I am parent!\n");
        }
    }
```

<br>

### 💡 `wait()` System Call
- 프로세스 A가 wait() 시스템 콜을 호출하면
    - 커널은 child가 종료될 대까지 프로세스 A를 sleep 시킨다. (block 상태)
    - child process가 종료되면 커널은 프로세스 A를 Rodnsek. (ready 상태)

## ✨ Reference ✨
[]()
