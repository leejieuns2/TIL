## 📌 안드로이드 파일 업로드 (Retrofit2)


### Retrofit2 Log 확인하는 방법

1. build.gradle 추가
    ```xml
    implementation 'com.squareup.okhttp3:okhttp:3.11.0'
    implementation 'com.squareup.okhttp3:logging-interceptor:3.11.0'
    ```

2. Interceptor 추가
    ```java
        Gson gson = new GsonBuilder().setLenient().create();

        OkHttpClient.Builder builder = new OkHttpClient.Builder();

        // 통신 중 일어나는 로그 Intercept
        HttpLoggingInterceptor logInterceptor = new HttpLoggingInterceptor();
        logInterceptor.setLevel(HttpLoggingInterceptor.Level.BODY);
        
        builder.interceptors().add(logInterceptor);

        OkHttpClient client = builder.build();
        retrofit = new Retrofit.Builder()
                .baseUrl(baseUrl)
                .client(client)
                .addConverterFactory(GsonConverterFactory.create(gson))
                .addCallAdapterFactory(RxJavaCallAdapterFactory.create())
                .build();
    ```
   
3. Log 확인 (Example)

    ```
    D/OkHttp: --> POST ((Retrofit url))
    Content-Type: application/x-www-form-urlencoded
    D/OkHttp: Content-Length: 86
    ((url parameter))
    --> END POST (86-byte body)
    D/TcpOptimizer: TcpOptimizer-ON
    D/OkHttp: <-- 200 OK ((Retrofit url)) (40ms)
    Server: Apache-Coyote/1.1
    Set-Cookie: JSESSIONID=((session ID)); Path=/((application name))/; HttpOnly
    Content-Type: text/html;charset=UTF-8
    Content-Length: 70
    Date: Thu, 18 Mar 2021 17:36:56 GMT
    D/OkHttp:  
    (( Response 출력됨 ))
    <-- END HTTP (70-byte body)
    ```

### Trouble Shooting
W/System.err: com.google.gson.stream.MalformedJsonException: Expected value at line 10 column 1 path $
at com.google.gson.stream.JsonReader.syntaxError(JsonReader.java:1568)
at com.google.gson.stream.JsonReader.doPeek(JsonReader.java:590)
at com.google.gson.stream.JsonReader.peek(JsonReader.java:425)
at com.google.gson.internal.bind.TypeAdapters$16.read(TypeAdapters.java:392)
at com.google.gson.internal.bind.TypeAdapters$16.read(TypeAdapters.java:389)
at retrofit2.converter.gson.GsonResponseBodyConverter.convert(GsonResponseBodyConverter.java:39)
at retrofit2.converter.gson.GsonResponseBodyConverter.convert(GsonResponseBodyConverter.java:27)
at retrofit2.ServiceMethod.toResponse(ServiceMethod.java:122)
at retrofit2.OkHttpCall.parseResponse(OkHttpCall.java:217)
at retrofit2.OkHttpCall.execute(OkHttpCall.java:180)
at retrofit2.ExecutorCallAdapterFactory$ExecutorCallbackCall.execute(ExecutorCallAdapterFactory.java:91)
at com.naru.project.awcs.service.AWCSClient.postImage(AWCSClient.java:99)
at com.naru.project.awcs.ui.camera.CameraActivity.uploadFile(CameraActivity.java:217)
at com.naru.project.awcs.ui.camera.CameraActivity$NThread.upload(CameraActivity.java:202)
W/System.err:     at com.naru.project.awcs.ui.camera.CameraActivity$NThread.run(CameraActivity.java:186)

- 찾아보니 서버 response 문제라고 함.
- response 데이터에 있는 유효하지 않은 데이터를 삭제하니 정상 작동됨.

https://jsonformatter.curiousconcept.com/#
- json 포맷 유효성 검사 가능 

## ✨ Reference ✨

- [https://g-song-ii.tistory.com/11](https://g-song-ii.tistory.com/11)
- [https://k9327.tistory.com/5](https://k9327.tistory.com/5)
- [https://privatedevelopnote.tistory.com/18](https://privatedevelopnote.tistory.com/18)
- [https://hun-developer.tistory.com/8](https://hun-developer.tistory.com/8)
- [https://soooprmx.com/archives/9626](https://soooprmx.com/archives/9626)
- [https://hashcode.co.kr/questions/2188/retrofit19-%EC%A7%88%EB%AC%B8%EB%93%9C%EB%A6%BD%EB%8B%88%EB%8B%A4](https://hashcode.co.kr/questions/2188/retrofit19-%EC%A7%88%EB%AC%B8%EB%93%9C%EB%A6%BD%EB%8B%88%EB%8B%A4)