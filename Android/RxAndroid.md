## 📌 RxAndroid & RxJava

### RxAndroid의 장점
- 다양한 비동기 처리 가능 (.flatmap()으로 순차적으로 실행되는 비동기 통신 가능)
- 복수의 비동기 처리 완료 후 결과 값을 합쳐야 할 경우 .merge()로 처리할 수 있어 간편
- 연속 클릭 이벤트로 발생한 이벤트 중복 실행 제어 가능
- 콜백 지옥 탈출 (unsubscriber)
- 모든 비동기 작업은 Observable<T> 형식으로 해결
- 다양한 쓰레드 관리 가능
- 코드가 깔끔해짐 (Lambda 사용)
- 읽기 전용의 Observable 사용 가능


### RxAndroid의 단점
- 진입 장벽이 높다.
- 코드가 오히려 복잡해질 수 있다. (단일 비동기 처리 시에는 오히려 사용을 안하는게 나을 수도 있음.)
- 메모리 관리에 유의해야 한다. (subscriber -> unsubscriber)


### RxJava란?
- 자바와 안드로이드를 위한 리액티브 프로그래밍 구현체로, 함수형 프로그래밍의 영향을 받았다.

### 리액티브 프로그래밍이란?
- 데이터나 이벤트 변화의 반응에 초점을 맞춘 프로그래밍을 뜻한다. (ex. 스프레드 시트)


### RxJava의 동작방식
- RxJava의 핵심은 이벤트 스트림을 나타내는 Observable타입이며, 이벤트 밀어내기(Push) 방식을 지향한다. 
  Observable과 그를 구독하는 Observer(Subscriber)의 쌍으로 구성되며, RxJava는 일반적으로 비동기로 동작한다. 
  기본값은 동기 방식으로 되어있으며, 명시적 요청이 없다면 동시성 처리를 하지 않는다.
- 여기서 단일 Observable은 동시성/병렬성 둘 다 허용하지 않는다. 대신 여러 비동기 Observable조합을 통해 이를 수행한다. 
  
    > #### 💡 동시성(Concurrency) 
    > : 싱글 코어에서 멀티 스레드를 동작시키는 방식, 동시에 실행되는 것 처럼 보이는 것, 실제론 번갈아 실행
    
    > #### 💡 병렬성(Parallelism) 
    > : 멀티 코어에서 멀티 스레드를 동작시키는 방식, 실제로 동시에 작업 처리되는 것

- onNext, onCompleted, onError 이벤트는 동시에 방출되지 않는다. 달리 말해, 하나의 Observable은 항상 직렬화되어 스레드에 안전해야 한다.
- Observable은 느긋(lazy)하다. Observer가 구독하지 않는 한 이벤트 방출을 시작하지 않는다.
- Observable은 재사용할 수 있다.

## ✨ Reference ✨

- [https://nittaku.tistory.com/179](https://nittaku.tistory.com/179)
- [https://archived.realignist.me/code/2016/05/29/rxjava-on-android.html](https://archived.realignist.me/code/2016/05/29/rxjava-on-android.html)