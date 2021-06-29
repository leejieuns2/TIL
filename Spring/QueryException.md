## 📌 QueryException 해결 방법

### 1. 에러 상황

#### org.hibernate.QueryException: query specified join fetching, but the owner of the fetched association was not present in the select list

```
    org.hibernate.QueryException: query specified join fetching, but the owner of the fetched association was not present in the select list 
    [FromElement{explicit,not a collection join,fetch join,fetch non-lazy properties,classAlias=hostUserMap,role=((package name)).Host.hostUserMaps,tableName=tb_host_user_map,tableAlias=hostuserma1_,origin=tb_host host0_,columns={host0_.seq,className=((package name)).HostUserMap}}]
    at org.hibernate.hql.internal.ast.tree.SelectClause.initializeExplicitSelectClause(SelectClause.java:217)
    at org.hibernate.hql.internal.ast.HqlSqlWalker.useSelectClause(HqlSqlWalker.java:1018)
    at org.hibernate.hql.internal.ast.HqlSqlWalker.processQuery(HqlSqlWalker.java:786)
    at org.hibernate.hql.internal.antlr.HqlSqlBaseWalker.query(HqlSqlBaseWalker.java:681)
    at org.hibernate.hql.internal.antlr.HqlSqlBaseWalker.selectStatement(HqlSqlBaseWalker.java:317)
    at org.hibernate.hql.internal.antlr.HqlSqlBaseWalker.statement(HqlSqlBaseWalker.java:265)
    at org.hibernate.hql.internal.ast.QueryTranslatorImpl.analyze(QueryTranslatorImpl.java:272)
    at org.hibernate.hql.internal.ast.QueryTranslatorImpl.doCompile(QueryTranslatorImpl.java:192)
    at org.hibernate.hql.internal.ast.QueryTranslatorImpl.compile(QueryTranslatorImpl.java:144)
    at org.hibernate.engine.query.spi.HQLQueryPlan.<init>(HQLQueryPlan.java:113)
    at org.hibernate.engine.query.spi.HQLQueryPlan.<init>(HQLQueryPlan.java:73)
    at org.hibernate.engine.query.spi.QueryPlanCache.getHQLQueryPlan(QueryPlanCache.java:155)
    at org.hibernate.internal.AbstractSharedSessionContract.getQueryPlan(AbstractSharedSessionContract.java:604)
    at org.hibernate.internal.AbstractSharedSessionContract.createQuery(AbstractSharedSessionContract.java:716)
    at org.hibernate.internal.AbstractSessionImpl.createQuery(AbstractSessionImpl.java:23)
    at sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method)
    at sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62)
    at sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43)
    at java.lang.reflect.Method.invoke(Method.java:498)
    at org.springframework.orm.jpa.ExtendedEntityManagerCreator$ExtendedEntityManagerInvocationHandler.invoke(ExtendedEntityManagerCreator.java:366)
    at com.sun.proxy.$Proxy130.createQuery(Unknown Source)
    at sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method)
    at sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62)
    at sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43)
    at java.lang.reflect.Method.invoke(Method.java:498)
    at org.springframework.orm.jpa.SharedEntityManagerCreator$SharedEntityManagerInvocationHandler.invoke(SharedEntityManagerCreator.java:314)
    at com.sun.proxy.$Proxy130.createQuery(Unknown Source)
    at com.querydsl.jpa.impl.AbstractJPAQuery.createQuery(AbstractJPAQuery.java:101)
    at com.querydsl.jpa.impl.AbstractJPAQuery.createQuery(AbstractJPAQuery.java:94)
    at com.querydsl.jpa.impl.AbstractJPAQuery.fetch(AbstractJPAQuery.java:201)
    at ((package name)).HostQdsl.findHostNameByHostUser(HostQdsl.java:179)
    at ((package name)).HostQdsl$$FastClassBySpringCGLIB$$e7f946b4.invoke(<generated>)
    at org.springframework.cglib.proxy.MethodProxy.invoke(MethodProxy.java:218)
    at org.springframework.aop.framework.CglibAopProxy$CglibMethodInvocation.invokeJoinpoint(CglibAopProxy.java:771)
    at org.springframework.aop.framework.ReflectiveMethodInvocation.proceed(ReflectiveMethodInvocation.java:163)
    at org.springframework.aop.framework.CglibAopProxy$CglibMethodInvocation.proceed(CglibAopProxy.java:749)
    at org.springframework.dao.support.PersistenceExceptionTranslationInterceptor.invoke(PersistenceExceptionTranslationInterceptor.java:139)
    at org.springframework.aop.framework.ReflectiveMethodInvocation.proceed(ReflectiveMethodInvocation.java:186)
    at org.springframework.aop.framework.CglibAopProxy$CglibMethodInvocation.proceed(CglibAopProxy.java:749)
    at org.springframework.aop.framework.CglibAopProxy$DynamicAdvisedInterceptor.intercept(CglibAopProxy.java:691)
    at ((package name)).domain.host.query.HostQdsl$$EnhancerBySpringCGLIB$$4102d73e.findHostNameByHostUser(<generated>)
    at ((package name)).domain.host.HostService.findHostNameByHostUser(HostService.java:47)
    at ((package name)).provider.ChannelTalkProvider.getChannelTalkUserInfo(ChannelTalkProvider.java:29)
    at ((package name)).controller.ChannelTalkController.getChannelTalkUserInfo(ChannelTalkController.java:22)
    at ((package name)).controller.ChannelTalkController$$FastClassBySpringCGLIB$$639d57b7.invoke(<generated>)
    at org.springframework.cglib.proxy.MethodProxy.invoke(MethodProxy.java:218)
    at org.springframework.aop.framework.CglibAopProxy$CglibMethodInvocation.invokeJoinpoint(CglibAopProxy.java:771)
    at org.springframework.aop.framework.ReflectiveMethodInvocation.proceed(ReflectiveMethodInvocation.java:163)
    at org.springframework.aop.framework.CglibAopProxy$CglibMethodInvocation.proceed(CglibAopProxy.java:749)
    at org.springframework.aop.aspectj.MethodInvocationProceedingJoinPoint.proceed(MethodInvocationProceedingJoinPoint.java:88)
    at ((package name)).aop.ControllerLogging.doLogging(ControllerLogging.java:45)
    at sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method)
    at sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62)
    at sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43)
    at java.lang.reflect.Method.invoke(Method.java:498)
    at org.springframework.aop.aspectj.AbstractAspectJAdvice.invokeAdviceMethodWithGivenArgs(AbstractAspectJAdvice.java:644)
    at org.springframework.aop.aspectj.AbstractAspectJAdvice.invokeAdviceMethod(AbstractAspectJAdvice.java:633)
    at org.springframework.aop.aspectj.AspectJAroundAdvice.invoke(AspectJAroundAdvice.java:70)
    at org.springframework.aop.framework.ReflectiveMethodInvocation.proceed(ReflectiveMethodInvocation.java:186)
    at org.springframework.aop.framework.CglibAopProxy$CglibMethodInvocation.proceed(CglibAopProxy.java:749)
    at org.springframework.aop.interceptor.ExposeInvocationInterceptor.invoke(ExposeInvocationInterceptor.java:95)
    at org.springframework.aop.framework.ReflectiveMethodInvocation.proceed(ReflectiveMethodInvocation.java:186)
    at org.springframework.aop.framework.CglibAopProxy$CglibMethodInvocation.proceed(CglibAopProxy.java:749)
    at org.springframework.aop.framework.CglibAopProxy$DynamicAdvisedInterceptor.intercept(CglibAopProxy.java:691)
    at ((package name)).controller.ChannelTalkController$$EnhancerBySpringCGLIB$$7306b06d.getChannelTalkUserInfo(<generated>)
    at sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method)
    at sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62)
    at sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43)
    at java.lang.reflect.Method.invoke(Method.java:498)
    at org.springframework.web.method.support.InvocableHandlerMethod.doInvoke(InvocableHandlerMethod.java:190)
    at org.springframework.web.method.support.InvocableHandlerMethod.invokeForRequest(InvocableHandlerMethod.java:138)
    at org.springframework.web.servlet.mvc.method.annotation.ServletInvocableHandlerMethod.invokeAndHandle(ServletInvocableHandlerMethod.java:105)
    at org.springframework.web.servlet.mvc.method.annotation.RequestMappingHandlerAdapter.invokeHandlerMethod(RequestMappingHandlerAdapter.java:879)
    at org.springframework.web.servlet.mvc.method.annotation.RequestMappingHandlerAdapter.handleInternal(RequestMappingHandlerAdapter.java:793)
    at org.springframework.web.servlet.mvc.method.AbstractHandlerMethodAdapter.handle(AbstractHandlerMethodAdapter.java:87)
    at org.springframework.web.servlet.DispatcherServlet.doDispatch(DispatcherServlet.java:1040)
    at org.springframework.web.servlet.DispatcherServlet.doService(DispatcherServlet.java:943)
    at org.springframework.web.servlet.FrameworkServlet.processRequest(FrameworkServlet.java:1006)
    at org.springframework.web.servlet.FrameworkServlet.doGet(FrameworkServlet.java:898)
    at javax.servlet.http.HttpServlet.service(HttpServlet.java:634)
    at org.springframework.web.servlet.FrameworkServlet.service(FrameworkServlet.java:883)
    at javax.servlet.http.HttpServlet.service(HttpServlet.java:741)
    at org.apache.catalina.core.ApplicationFilterChain.internalDoFilter(ApplicationFilterChain.java:231)
    at org.apache.catalina.core.ApplicationFilterChain.doFilter(ApplicationFilterChain.java:166)
    at org.apache.tomcat.websocket.server.WsFilter.doFilter(WsFilter.java:53)
    at org.apache.catalina.core.ApplicationFilterChain.internalDoFilter(ApplicationFilterChain.java:193)
    at org.apache.catalina.core.ApplicationFilterChain.doFilter(ApplicationFilterChain.java:166)
    at org.springframework.web.filter.CharacterEncodingFilter.doFilterInternal(CharacterEncodingFilter.java:201)
    at org.springframework.web.filter.OncePerRequestFilter.doFilter(OncePerRequestFilter.java:119)
    at org.apache.catalina.core.ApplicationFilterChain.internalDoFilter(ApplicationFilterChain.java:193)
    at org.apache.catalina.core.ApplicationFilterChain.doFilter(ApplicationFilterChain.java:166)
    at org.apache.catalina.core.StandardWrapperValve.invoke(StandardWrapperValve.java:202)
    at org.apache.catalina.core.StandardContextValve.invoke(StandardContextValve.java:96)
    at org.apache.catalina.authenticator.AuthenticatorBase.invoke(AuthenticatorBase.java:541)
    at org.apache.catalina.valves.AbstractAccessLogValve.invoke(AbstractAccessLogValve.java:688)
    at org.apache.catalina.core.StandardHostValve.invoke(StandardHostValve.java:139)
    at org.apache.catalina.valves.ErrorReportValve.invoke(ErrorReportValve.java:92)
    at org.apache.catalina.core.StandardEngineValve.invoke(StandardEngineValve.java:74)
    at org.apache.catalina.connector.CoyoteAdapter.service(CoyoteAdapter.java:343)
    at org.apache.coyote.http11.Http11Processor.service(Http11Processor.java:373)
    at org.apache.coyote.AbstractProcessorLight.process(AbstractProcessorLight.java:65)
    at org.apache.coyote.AbstractProtocol$ConnectionHandler.process(AbstractProtocol.java:868)
    at org.apache.tomcat.util.net.NioEndpoint$SocketProcessor.doRun(NioEndpoint.java:1594)
    at org.apache.tomcat.util.net.SocketProcessorBase.run(SocketProcessorBase.java:49)
    at java.util.concurrent.ThreadPoolExecutor.runWorker(ThreadPoolExecutor.java:1149)
    at java.util.concurrent.ThreadPoolExecutor$Worker.run(ThreadPoolExecutor.java:624)
    at org.apache.tomcat.util.threads.TaskThread$WrappingRunnable.run(TaskThread.java:61)
    at java.lang.Thread.run(Thread.java:748)
```

<br>

### 2. 원인
- join() 를 사용해야 하는 QueryDsl 코드에서 fetchJoin()을 사용했기 때문에.

<br>

### 3. 해결 방법
- fetchJoin()이 아니라 join()만 사용할 것.
  
- fetchJoin()이 무조건적인 해답이 아님. fetch join을 사용하는 이유는 엔티티를 select하는 상태에서 엔티티 그래프를 참조하기 위해서 사용하는 것이기 때문에
  엔티티를 select하는 것이 아니라 DTO나 하나의 컬럼을 select하는 상황이라면 fetch join이 아니라 DTO 상태의 select를 지원하는 join()를 사용하는 것이 맞음.
  
- 여기서 엔티티 그래프를 참조한다는 것은 엔티티를 select해 엔티티 내 변수들을 사용한다는 의미다. (User Entity를 select 했을 경우 User.username이나 User.userId를 사용해 어떠한 로직을 처리하는 것을 의미함.)


## ✨ Reference ✨
[https://www.inflearn.com/questions/23847](https://www.inflearn.com/questions/23847)