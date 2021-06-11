## 📌 Spring Framework


<br>


### Spring Framework 란?

- 기업의 정보 시스템과 응용 서비스를 개발하는데 널리 사용되는 Java 기반의 Open Source Framework

- Enterprise application을 개발하는데 있어 복잡성을 줄이고 생산성과 효율성, 신뢰성을 높여주는 여러 가지 기능 및 도구들을 제공함.

- 국내 전자정부 표준 프레임워크(eGovFrame)의 기반 기술로 사용됨. 표준화된 SW 개발 및 운영 환경을 제공하여 정부 및 공공기관에서 널리 사용됨.   
  💡 [국내 표준프레임워크 포털 바로가기](https://www.egovframe.go.kr/home/main.do)


<br>


### Spring Framework의 특징

1. DI(Dependency Injection) : 의존성 주입 지원 

   - xml, annotation, java code 기반 설정을 통해 객체들 간의 의존 관계 설정
    
   - 객체 외부에 존재하는 컨테이너가 런타임시 객체들 사이의 의존 관계를 파악하고 의존 객체를 객체에 제공해 주는 것을 의미함.
    
   - 객체 생성 시점에 의존 객체가 객체에 제공됨 (Bean Wiring)

    ex) @Autowired, @Bean, @Component Annotation


2. AOP(Aspect-Oriented Programming) : 관점 지향 프로그래밍 지원 
   - 핵심 business logic과 system services 사이의 독립성 보장
    
   - 공통의 관심사항 적용 시 발생하는 의존 관계의 복잡성과 코드 중복 문제를 해결하기 위한 프로그래밍 기법
    
   - 공통 기능을 별도로 모듈화하여 구현하고 Aspect를 통해 비즈니스 클래스에 선언적으로 적용
    
   - 비즈니스 클래스와 시스템 서비스 사이의 의존성 해결

3. Light-weight container and framework
   - 크기가 작고 성능이 우수함
     
   - Java 기반 객체의 life-cycle 관리
     
   - Enterprise application 개발을 위한 다양한 시스템 서비스 제공

4. JDBC, JPA, 선언적 transaction 처리 등 데이터베이스 연동 지원


<br>


### Spring Framework의 장점
1. Plain Old Java Objects(POJOs)를 이용한 쉬운 개발
   (lightweight development)

2. Dependency Injection과 Interface를 활용한 객체들 간의 느슨한 결합

3. Aspects와 common conventions, annotation을 통한 선언적 프로그래밍
   (declarative programming)
   
4. Aspects와 templates를 이용한 단순 반복 코드 제거 (Boilerplate reduction)

<br>


### Spring Framework의 단점


<br>


### Spring Boot

- 간단한 설정만으로 빠르게 실행 가능하도록 독립적인 Spring Application 개발을 지원하는 Spring framework의 확장 기능

- Spring framework와 3rd party library들에 대한 복잡하고 반복적인 설정 코드를 최소화하고 비즈니스 로직 구현에 집중 가능

1. 특징
- 내장된 Tomcat 지원
- starter dependency를 통한 단순한 build 의존성 설정
- 명시적인 xml 설정이나 Java 코드 설정 제거 및 최소화
- 애플리케이션의 모니터링 및 관리를 위한 actuator 기능


<br>


### Spring MVC


<br>


### Spring Boot vs Spring MVC


<br>


## ✨ Reference ✨