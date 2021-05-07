## 📌 오픈소스 라이브러리 종류

### Apache License
- 아파치 라이선스(Apache License)는 자신들의 소프트웨어에 적용하기 위하여 아파치 소프트웨어 재단 자체적으로 만든 라이선스이다. 
  소스코드에 대한 공개 의무 등의 의무사항은 없지만 아파치 라이선스의 소스코드를 수정하여 배포하는 경우 아파치 라이선스, 버전 2.0을 꼭 포함시켜야 하며 아파치 재단에서 만든 소프트웨어임을 밝혀야 한다.
- ex ) 안드로이드(Android), 하둡(Hadoop)

### GNU(Gnu is Not Unix) General Public License(GPL)
- 자유 소프트웨어 재단(Free Software Foundation, FSF)에서 만든 라이선스로 GNU 프로젝트로 배포하는 소프트웨어(Emacs, GNU 디버거(GDB), GNU 컴파일러 모음(GCC) 등)에 적용하기 위하여 리처드 스톨먼(Richard Stallman)이 만든 라이선스이다. 
  가장 큰 특징은 자유 소프트웨어 재단 답게 가장 강한 제약 조건을 포함하고 있는 카피레프트(Copyleft) 조항. GPL 프로그램은 어떤 목적으로, 어떤 형태로든 사용할 수 있지만 사용하거나 변경된 프로그램을 배포하는 경우 무조건 동일한 라이선스 즉, GPL로 공개해야 한다는 강력한 조항이 담겨있다.

- ex ) Mozilla Firefox, Linux 커널, Git, MariaDB, Wordpress, Drupal

### GNU Affero GPL(AGPL)
- GPL을 기반으로 만든 라이선스로 버전1, 2는 Affero, 가장 최신 버전인 버전3은 자유 소프트웨어 재단에 의하여 개발되었다. 
  수정한 소스코드를 서버에서만 사용하는 개발자가 그 프로그램을 배포하지 않을 경우 사용자는 소스코드를 가질 수가 없는 문제를 해결하기 위하여 서버에서 프로그램을 실행하여 다른 사용자들과 통신하게 된다면, 실행되고 있는 프로그램의 소스 코드를 사용자들이 다운로드 받을 수 있게 해야 한다는 독특한 조항이 담겨있다.
- ex ) MongoDB(v3.0)

### GNU Lesser GPL(LGPL)
- 자유 소프트웨어 재단의 강력한 철학이 담긴 GPL의 카피레프트 조항을 보완하기 위하여 만든 라이선스이다. 
  단순히 소프트웨어를 사용하기만 하더라도 해당 소스코드를 GPL로 공개해야 하는 부담감 때문에 상용 소프트웨어로서는 쓰이기 부담스러운 단점이 있다. 
  따라서 좋은 자유 소프트웨어 제품이 더 많이 사용될 수 있고 표준이 되도록 유도하기 위하여 단순한 라이브러리/모듈 링크를 허용한 라이선스이다. 원래는 한정된 라이브러리에만 적용하기 위한 의도로 'Library GPL'이라는 이름이였으나 모든 라이브러리에 적용된다는 오해를 사 'Lesser GPL'로 변경되었다.
- ex ) Mozilla Firefox(v2.1)

### MIT License
- MIT 라이선스(MIT License)는 미국 매사추세츠 공과대학교(MIT)에서 해당 대학의 소프트웨어 공학도들을 돕기 위해 개발한 라이선스다. 
  라이선스와 저작권 관련 명시만 지켜주면 되는 라이선스로 가장 느슨한 조건을 가진 라이선스 중 하나기 때문에 인기가 많다.
- ex ) Bootstrap, Angular.js, Backbone.js, jQuery

### Artistic License
- Perl 프로그래밍 언어를 사용하던 Larry Wall이 표준 펄(Perl) 기능을 위해 개발한 라이선스로, 이 단어의 어원은 문학에서 문법상 틀린 표현이라도 시적인 효과를 위하여 허용하는 것을 의미하는 'Articstic License'(시적 허용)를 참조하여 만들어졌다.
- ex ) NPM(Node Package Manager)(v2.0)

### Eclipse License
- 이클립스사에서 비즈니스 환경에 적합하도록 만든 기업 친화적인 라이선스로 강력한 카피레프트 조항이 담긴 GPL보다 제약 조건이 완화된 라이선스이다.
- ex ) Eclipse(v1.0)

### Berkeley Software Distribution(BSD) License
- 버클리의 캘리포니아 대학에서 배포하는 공개 소프트웨어의 라이선스이다. BSD 라이선스의 경우에는 BSD 자체가 공공기관에서 만들어낸 것이므로 공공의 몫으로 돌려주자는 의미가 강하므로 라이선스 자체에는 아무런 제한 없이 누구나 자신의 용도로 사용할 수 있도록 만들어진 것으로 라이선스 및 저작권 표시 조건 외에 굉장히 자유로운 라이선스 중 하나이다.
- ex ) Nginx(The BSD 2-Clause License)

### Mozilla Public License(MPL)
- 모질라 공용 허가서(Mozilla Public License, MPL)는 과거 넷스케이프(Netscape) 브라우저의 소스코드를 공개하기 위해 개발된 라이선스이다. 초기 1.0 버전은 넷스케이프 커뮤니케이션즈 코퍼레이션스의 변호사였던 미첼 베이커(Mitchell Baker)가 작성하였고 이후 1.1, 2.0 버전은 모질라 재단이 작성하였다. 
  MPL의 특징은 소스코드와 실행파일의 저작권을 분리함으로써 수정한 소스코드의 경우 MPL로 공개하고 원저작자에게 수정한 부분에 대해 알려야 하지만 실행파일은 독점 라이선스로 배포가 가능한 점이다. 즉, 사용한 MPL 소프트웨어와 수정한 MPL 소프트웨어에 대한 공개 의무만을 가지며 별도의 소스코드와 실행파일은 독점 라이선스를 가질 수 있다.
- ex ) Mozilla Firefox(v1.1), Mozilla Thunderbird(v1.1)


<br>


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

### 3. Activity 연결

```java
import com.google.android.gms.oss.licenses.OssLicensesMenuActivity;

// ...

// When the user selects an option to see the licenses:
startActivity(new Intent(this, OssLicensesMenuActivity.class));
OssLicensesMenuActivity.setActivityTitle(getString(R.string.custom_license_title));
```


## ✨ Reference ✨

- [https://github.com/google/play-services-plugins/tree/master/oss-licenses-plugin](https://github.com/google/play-services-plugins/tree/master/oss-licenses-plugin)