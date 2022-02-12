# Chapter 5. CPU Scheduling

### 💡 CPU and I/O Bursts in Program Execution

![](../../image/cpu_io_burst.png)

- 명령어 실행 도중 I/O 작업으로 넘어가면 wait이 발생하게 됨.
- CPU만 연속적으로 사용하는 CPU burst 상태와 I/O만 연속되어 발생하는 I/O Burst 상태가 반복되게 됨.
- 주로 사람이 연결되어 있는 프로그램에서 주로 반복되는 형태가 많이 발생함 (interactive한 job)
- 프로그램의 종류에 따라 빈도나 유형이 각각 다름.

<br>

### 💡 CPU-burst time의 분포

![](../../image/cpu_burst_time.png)

- 여러 종류의 job(=process)이 섞여 있기 때문에 CPU 스케쥴링이 필요하다.
    - 중간에 I/O가 많으면 CPU bust time이 적음. (= I/O bound job) -> 반대가 CPU bound job
    - CPU를 많이 사용하는 것은 CPU bound job이라고 보는게 맞고, 유
      I/O bound job은 I/O가 빈번하기 때문에 스위칭이 잦아 CPU 사용률이 많아 보이는 것. (frequency가 높은 이유)
    - interactive job에게 적절한 response 제공 필요
    - CPU와 I/O 장치 등 시스템 자원을 골고루, 효율적으로 사용해야 함. -> CPU Scheduling이 필요한 이유

<br>

## < 요약 >
### 💡 프로세스의 특성 분류
1. I/O-bound process
   - CPU를 잡고 계산하는 시간보다 I/O에 많은 시간이 필요한 job (= 유저와의 interaction이 잦은 작업)
2. CPU-bound process
   - 계산 위주의 job

<br>

### 💡 CPU Scheduler & Dispatcher
1. CPU Scheduler
   - Ready 상태의 프로세스 중에서 이번에 CPU를 줄 프로세스를 고른다.
   - OS의 특정적인 기능 (code)를 Scheduler라고 부르는 것.
  
2. Dispatcher
   - CPU의 제어권을 CPU Scheduler에 의해 선택된 프로세스에게 넘긴다.
   - 이 과정을 context switch(문맥 교환)라고 한다.
  
3. CPU 스케쥴링이 필요한 경우
   - 프로세스에게 다음과 같은 상태 변화가 있는 경우 스케쥴링이 필요하다.
  1. Running -> Blocked (예 : I/O 를 요청하는 System call)
  2. Running -> Ready (예 : 할당시간만료로 timer interrupt)
  3. Blocked -> Ready (예 : I/O 완료 후 인터럽트)
  4. Terminate

  ** 1,4에서의 스케쥴링은 nonpreemptive (강제 x, 자진 반납)
  ** 1,4번을 제외한 스케쥴링은 preemptive (강제로 문맥교환 발생)

