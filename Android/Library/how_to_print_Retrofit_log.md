## 📌 Retrofit2 Log 확인하는 방법

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