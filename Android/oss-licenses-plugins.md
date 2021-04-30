## 📌 구글 오픈소스 라이센스 표기 라이브러리 사용법

### 1. build.gradle(Module) 추가
```java
apply plugin: 'com.google.android.gms.oss-licenses-plugin'
```  

### 2. build.gradle(Project) 추가
```java

buildscript{
    repositories{
        // ...
        google()  // or maven { url "https://maven.google.com" } for Gradle <= 3
    }
    ...
    dependencies {
        // ...
        // Add this line:
        classpath'com.google.android.gms:oss-licenses-plugin:0.10.4'
    }
}
```



```java
```
## ✨ Reference ✨

- [https://github.com/google/play-services-plugins/tree/master/oss-licenses-plugin](https://github.com/google/play-services-plugins/tree/master/oss-licenses-plugin)