## 📌 CLEARTEXT communication to *** not permitted by network security policy 에러 해결 방법


### 💡 에러 Log
```
I/okhttp.OkHttpClient: <-- HTTP FAILED: java.net.UnknownServiceException: CLEARTEXT communication to ((IP Address)) not permitted by network security policy
W/System.err: java.net.UnknownServiceException: CLEARTEXT communication to ((IP Address)) not permitted by network security policy
        at okhttp3.internal.connection.RealConnection.connect(RealConnection.kt:188)
        at okhttp3.internal.connection.ExchangeFinder.findConnection(ExchangeFinder.kt:226)
        at okhttp3.internal.connection.ExchangeFinder.findHealthyConnection(ExchangeFinder.kt:106)
        at okhttp3.internal.connection.ExchangeFinder.find(ExchangeFinder.kt:74)
        at okhttp3.internal.connection.RealCall.initExchange$okhttp(RealCall.kt:255)
        ...
```


### 💡 에러 발생 이유
- 네트워크 경로(API 주소 등)가 https가 아닌 http로 설정되어 있기 때문에 발생하는 문제.
- 보통 이런 에러는 https를 사용하도록 강제하는 안드로이드 버전 9.0(Pie)일 때 발생함.


<br>


### 💡 에러 해결 방법

#### 1. 네트워크 주소 변경 (http -> https)

#### 2. 1번을 수행할 여건이 되지 않는다면 network_security_config.xml 생성
   (위의 파일은 네트워크 주소가 http여도 정상적으로 서버 통신이 가능하도록 도와주는 역할을 수행함.)

2-1. res/xml/network_security_config.xml 파일 생성
```xml
<?xml version="1.0" encoding="utf-8"?>
<!--res/xml/network_security_config.xml-->
<network-security-config>
    <domain-config cleartextTrafficPermitted="true">
        <domain includeSubdomains="true">api.xxx.com</domain>
    </domain-config>
</network-security-config>
```

2-2. androidManifest.xml에 networkSecurityConfig 속성 추가

```xml
<?xml version="1.0" encoding="utf-8"?>
<application
    android:networkSecurityConfig="@xml/network_security_config"/>
```

<br>


## ✨ Reference ✨
- [https://gun0912.tistory.com/80](https://gun0912.tistory.com/80)