## 📌 DataBinding

> - 데이터 바인딩이란, 레이아웃의 UI 구성요소를 선언적 형식을 사용하여 데이터 소스에 결합하는 방식을 의미한다.
> - 데이터 바인딩을 사용해 불필요한 코드 (계속적인 findViewById 호출 등)를 줄일 수 있으며, 보통 MVVM 패턴과 같이 사용한다.


<br> 

### DataBinding 사용 방법 - 1) build.gradle 설정
- DataBinding 라이브러리는 Android Gradle 플러그인과 함께 번들로 제공되기 때문에 따로 Dependency 선언할 필요는 없지만, 사용 설정이 필요하다.
- 사용 설정하려면 아래와 같이 모듈의 build.gradle 파일에서 dataBinding 빌드 옵션을 true로 설정합니다.

    ```xml
    android {
        ...
        buildFeatures {
            dataBinding true
        }
    }
    ```

- 레이아웃은 흔히 UI 프레임워크 메서드를 호출하는 코드가 포함된 활동에서 정의됩니다. 예를 들어 아래 코드는 findViewById()를 호출하여 TextView 위젯을 찾아 viewModel 변수의 userName 속성에 결합합니다.

  ```kotlin
    findViewById<TextView>(R.id.sample_text).apply {
        text = viewModel.userName
    }
  ```


### DataBinding 사용 방법 - 2) Layout에서 DataBinding 사용하기

```xml
<layout 
        xmlns:android="http://schemas.android.com/apk/res/android"
        xmlns:app="http://schemas.android.com/apk/res-auto">
    <data>
        <variable
            name="viewmodel"
            type="com.myapp.data.ViewModel" />
    </data>
    <ConstraintLayout... /> <!-- UI layout's root element -->
</layout>
```

```xml
<!-- in UI layout's root element -->
<TextView
        android:text="@{viewmodel.userName}" />
```
- DataBinding을 사용하려면 레이아웃 파일의 루트 태그에 ‘layout’ 을 추가해야 한다.
- DataBinding은 레이아웃의 뷰를 연결하고 싶은 Model과 결합하는 데 필요한 클래스를 자동으로 생성한다. 때문에 표현식로 레이아웃의 뷰와 Model의 Data를 연결할 수 있다.
- data 내에 있는 viewModel 변수는 이 레이아웃 내에서 사용할 수 있는 속성에 대한 설명이다. 레이아웃 내에 있는 식은 “@{}” 구문을 사용하여 특성 속성에 기록된다. 여기서 TextView의 텍스트는 위에 설정한 viewModel의 userName 속성으로 설정된다.
- 레이아웃 파일에서 구성요소를 결합하면 Activity Class에서 많은 UI 프레임워크 호출 코드(findViewById 등)를 삭제할 수 있어 파일이 더욱 단순화되고 코드의 유지보수가 쉬워진다. 이로 인해 앱 성능이 향상되고, 메모리 누수 및 NullPointerException을 방지할 수 있다.


## ✨ Reference ✨

- [https://developer.android.com/topic/libraries/data-binding?hl=ko](https://developer.android.com/topic/libraries/data-binding?hl=ko)
- [https://developer.android.com/jetpack/androidx/releases/databinding?hl=ko](https://developer.android.com/jetpack/androidx/releases/databinding?hl=ko)
- [https://junghun0.github.io/2019/05/22/android-databinding/](https://junghun0.github.io/2019/05/22/android-databinding/)
