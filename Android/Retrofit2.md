
## 📌 Retrofit

### 1. Retrofit 이란?

- Retrofit은 REST API 통신을 위해 구현된 라이브러리이다. AsyncTask 없이 Background Thread에서 실행되며 callback을 통해 Main Thread에서의 UI 업데이트를 간단하게 할 수 있도록 제공하고 있다.

    > Retrofit 문서 : http://devflow.github.io/retrofit-kr/
   
  
### 2. Retrofit을 사용하는 이유?
- Retrofit 이외에 다른 라이브러리도 있지만 Retrofit을 사용하기로 한 이유는 성능과 간단한 구현방법 때문이다. Retrofit은 AsyncTask로 구현된 통신이나 Volley에 비해 응답속도가 매우 빠른것으로 나와있다. 또한 동기/비동기 방식을 선택할 수 있으며 Call의 요청을 취소할 수도 있다.

    > 참고 : http://instructure.github.io/blog/2013/12/09/volley-vs-retrofit/

- Retrofit2 는 기본적으로 OkHttp를 네트워킹 계층으로 활용하며 그 위에 구축된다.


## 3. Retrofit 사용 방법

1) build.gradle implementation
   
    ```
    implementation 'com.squareup.retrofit2:retrofit:버전정보'
    implementation 'com.squareup.retrofit2:converter-gson:버전정보'
    ```
   
2) AndroidManifest에 인터넷 권한 추가
   
   ```
   ...
   <uses-permission android:name="android.permission.INTERNET" />
   ...
   ```

## ✨ Reference ✨

- [https://huiveloper.tistory.com/13](https://huiveloper.tistory.com/13)
- [https://woovictory.github.io/2019/01/03/Android-What-is-retrofit/](https://woovictory.github.io/2019/01/03/Android-What-is-retrofit/)
- [https://github.com/HwangEunmi/Retrofit-Sample#retrofit%EC%97%90%EC%84%9C-%EB%A9%80%ED%8B%B0%ED%8C%8C%ED%8A%B8-%ED%86%B5%EC%8B%A0%ED%95%98%EA%B8%B0](https://github.com/HwangEunmi/Retrofit-Sample#retrofit%EC%97%90%EC%84%9C-%EB%A9%80%ED%8B%B0%ED%8C%8C%ED%8A%B8-%ED%86%B5%EC%8B%A0%ED%95%98%EA%B8%B0)