##  📌 View Binding

<br>

### 1. View Binding이란?
- 뷰 바인딩(View Binding) 은 뷰와 상호 작용하는 코드를 보다 쉽게 작성할 수 있는 기능이다.
- 모듈의 build.gradle에서 뷰 바인딩 속성이 활성화되면 해당 모듈에 있는 각 XML 레이아웃 파일에 대한 바인딩 클래스가 자동으로 생성됩니다. 바인딩 클래스 인스턴스에는 해당 레이아웃에 ID가 있는 모든 뷰에 대해 직접적으로 참조됩니다.
- 대부분 경우에 있어, 뷰 바인딩을 사용하는 것으로 findViewById 메서드를 대체할 수 있습니다.


### 2. ViewBinding 설정하기
- 뷰 바인딩은 Android Studio 3.6부터 사용가능합니다.
- 뷰 바인딩은 각 모듈별로 활성화됩니다. 모듈에서 뷰 바인딩을 사용하려면 다음 예제와 같이 viewBinding 요소를 build.gradle 파일에 추가하십시오.

```xml
    android {
        ...
        viewBinding {
            enabled = true
        }
    }
```

- 바인딩 클래스를 생성하는 동안 레이아웃 파일을 무시하려면 `tools : viewBindingIgnore = “true”` 속성을 해당 레이아웃 파일의 최상단 루트 뷰에추가하십시오.

```xml
    <LinearLayout
        ...
        tools:viewBindingIgnore="true" >
        ...
    </LinearLayout>
```

### 3. ViewBinding 사용법
- 모듈에 대해 뷰 바인딩을 사용하는 경우, 포함된 각 XML 레이아웃 파일에 대해 바인딩 클래스가 생성됩니다. 각 바인딩 클래스에는 루트뷰 및 ID가있는 모든 뷰에 대한 참조가 포함됩니다. 바인딩 클래스의 이름은 XML 파일의 이름을 Camel case로 변환하고 접미어 “Binding”이 추가됩니다.
예를 들어 result_profile.xml이라는 레이아웃 파일이 아래와 같이 있다면,
  ```java
    <LinearLayout ... >
        <TextView android:id="@+id/name" />
        <ImageView android:cropToPadding="true" />
        <Button android:id="@+id/button"
        android:background="@drawable/rounded_button" />
    </LinearLayout>
  ```

- 생성되는 바인딩 클래스의 이름은 ResultProfileBinding가 됩니다. 이 클래스에는 name이라는 ID를 갖는 TextView와 button이라는 ID를 갖는 Button 필드를 갖습니다. 레이아웃의 ImageView에는 ID가 없으므로 바인딩 클래스에 대한 참조가 없습니다.
모든 바인딩 클래스에는 해당 레이아웃 파일의 루트뷰에 대한 직접 참조를 제공하는 getRoot() 메소드도 포함되어 있습니다. 이 예제에서 ResultProfileBinding 클래스의 getRoot() 메소드는 LinearLayout 루트보기를 반환합니다.
생성된 바인딩 클래스의 인스턴스를 얻으려면 정적 inflate() 메소드를 호출하십시오. 일반적으로 setContentView()를 호출하여 클래스의 루트뷰를 매개 변수로 전달하여 화면에서 활성화된 뷰로 만듭니다. 아래의 예제에서는 액티비티에서 ResultProfileBinding.inflate()를 호출하고, setContentView에 루트뷰를 적용하는 예제를 보여줍니다.

  ```kotlin
  private lateinit var binding: ResultProfileBinding
    
  @Override
  fun onCreate(savedInstanceState: Bundle) {
      super.onCreate(savedInstanceState)
      binding = ResultProfileBinding.inflate(layoutInflater)
      setContentView(binding.root)
  }
  ...
  // 바인딩 클래스의 인스턴스를 사용하여 모든 뷰 참조 가능.
  binding.name.text = viewModel.name
  binding.button.setOnClickListener { viewModel.userClicked() }
  ```

### 4. findViewById와의 차이점
- 뷰 바인딩은 findViewById를 사용하는 것보다 중요한 장점을 가지고 있습니다.
- Null safety: 뷰 바인딩은 뷰에 대한 직접 참조를 생성하므로 잘못된 뷰 ID로 인해 NPE(Null Pointer Exception)발생할 위험이 없습니다. 또한 뷰가 레이아웃의 일부 구성에만있는 경우 바인딩 클래스에 해당 참조가 포함 된 필드는 `@Nullable`로 표시됩니다.
- Type safety: 각 바인딩 클래스의 필드에는 XML 파일에서 참조하는 뷰와 일치하는 타입을 갖고 있습니다. 이것은 클래스를 캐스팅할 때 발생할수 있는 오류가 없음을 의미합니다.
- 레이아웃 파일과 실제 자바/코틀린 코드간에 일치하지 않아 발생하는 문제가 런타임이 아닌 컴파일타임에 발생하기 때문에 더 빠르게 에러를 잡고, 개발자는생산성을 늘릴 수 있습니다.

### 5. Data binding과 View binding의 차이
- 뷰 바인딩과 데이터 바인딩 라이브러리 둘다 뷰를 직접 참조하는 바인딩 클래스를 생성합니다. 그러나 주목할만한 차이점이 있습니다.
- 데이터 바인딩 라이브러리는 <layout> 태그를 사용하여 만든 레이아웃만 처리합니다.
- 뷰 바인딩은 레이아웃 변수 또는 레이아웃 표현식을 지원하지 않으므로 XML의 데이터와 레이아웃을 바인딩하는 데 사용할 수 없습니다.
- 내부적으로 데이터 바인딩 클래스를 생성할때 루트뷰에 tag를 삽입하는데 뷰바인딩은 그런 작업이 필요하지 않아 데이터바인딩보다 어노테이션 프로세싱의 일부를 사용해 더 빠르게 바인딩 클래스를 생성할 수 있습니다.


## ✨ Reference ✨

- [https://developer.android.com/topic/libraries/view-binding?hl=ko](https://developer.android.com/topic/libraries/view-binding?hl=ko)
- [https://tourspace.tistory.com/314](https://tourspace.tistory.com/314)
- [https://duckssi.tistory.com/42](https://duckssi.tistory.com/42)