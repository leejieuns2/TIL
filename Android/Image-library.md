
## ๐ ์๋๋ก์ด๋ ์ด๋ฏธ์ง ๋ก๋ฉ ๋ผ์ด๋ธ๋ฌ๋ฆฌ


### โ ImageView ์ฌ์ฉ 

1. ์๋๋ก์ด๋ ์ฑ ์์ drawableํด๋์ ๋ฆฌ์์ค๋ฅผ ๋ณด์ฌ์ฃผ๋ ๊ฒฝ์ฐ
2. ์๋๋ก์ด๋ ๋๋ฐ์ด์ค ์์ ์ ์ฅ๋์ด์๋ ์ฌ์ง์ ๋ณด์ฌ์ฃผ๋ ๊ฒฝ์ฐ(๊ฐค๋ฌ๋ฆฌ ํน์ ๊ธฐํ ๋ด๋ถ ์ฌ์ง)
3. ์ด๋ฏธ์ง URL์ ๋ก๋ํด์ ๋ณด์ฌ์ฃผ๊ณ ์ ํ๋ ๊ฒฝ์ฐ

- 1,2๋ฒ์ ๊ฒฝ์ฐ๋ ์๋๋ก์ด๋ ๊ธฐ๊ธฐ ๋ด๋ถ์ ๋ฆฌ์์ค๋ฅผ ๋ถ๋ฌ์ค๋ ์์์ด๋ฏ๋ก ์์ธ์ฌํญ๋ ์ ๊ณ  ์ค์  ๊ตฌํ๋ ๋ณต์กํ์ง ์์ต๋๋ค.
๊ทธ๋ฌ๋ 3๋ฒ์ฒ๋ผ ์ด๋ฏธ์ง์ URL์ธ ๊ฒฝ์ฐ httpํด๋ผ์ด์ธํธ๋ฅผ ์ด์ฉํด์ ImageView์ ๋ณด์ฌ์ฃผ์ด์ผ ํ๋๊ฒฝ์ฐ๋ ๊ณ ๋ คํด์ผํ  ์ฌํญ์ด ๋ง์ต๋๋ค.   
    => ๋ก๋ฉ ์คํจ์ฒ๋ฆฌ, ์ฌ์๋์ฒ๋ฆฌ, Out of Memory, ์บ์,๋ณ๋ ฌ์ฒ๋ฆฌ, ๋์ฝ๋ฉ, ์ด๋ฏธ์ง์ฌํ์ฉ ๋ฑ๋ฑ

 
> ๐ก ์์ฝํ๋ฉด, ์ด๋ฏธ์ง ๋ก๋ฉ์ ๊ตฌํํ  ๋๋ HTTP ํต์ ์ ์์ ๋๊ฒ ๊ตฌํํ๊ณ , ๋นํธ๋งต์ผ๋ก ๋์ฝ๋ฉํ๋ฉด์ ๋ฉ๋ชจ๋ฆฌ๊ฐ ๋์น๊ฑฐ๋ ์์ง ์๋๋ก ์ฃผ์ํด์ผ ํ๋ค. ํ์ง๋ง, ๋คํธ์ํฌ ํธ์ถ๊ณผ ๋์ฝ๋ฉ์ ๋จ์ํ ๋ฐฑ๊ทธ๋ผ์ด๋ ์ค๋ ๋์์ ๋์ํ๋ ๊ฒ๋ง์ผ๋ก๋ ์ถฉ๋ถํ์ง ์๊ณ  ๋ ์ ๊ทน์ ์ผ๋ก ๋ณ๋ ฌ์ฑ์ ํ์ฉํด์ผ ํ๋ค. ํ๋ฉด ํ์ , ์ ํ, ์คํฌ๋กค ๋ ๋ฐ๋ณต์ ์ธ ์์ฒญ์ด ๊ฐ์ง ์๋๋ก ์ด๋ฏธ์ง๋ฅผ ์บ์ํ๊ณ , ๋ถํ์ํด์ง ์์ฒญ์ ๋น ๋ฅธ ์์ ์ ์ทจ์ํด์ ๋ ๋์ UI ๋ฐ์์ ์ ๊ณตํ๋ฉด์ ์์์ ์ ์ฝํด์ผ ํ๋ค. ์ด ๊ณผ์ ๋ค์ ๋ชจ๋ ํด๊ฒฐํ๋ ค๋ค ๋ณด๋ฉด ์ฒ๋ฆฌ ํ๋ฆ์ ๋ณต์กํด์ง๊ณ , ๋น์ทํ ์ฝ๋๊ฐ ๋ฐ๋ณต๋๊ธฐ ์ฝ๋ค.
๊ทธ๋์ ์ฐ๋ฆฌ๋ ์ด๋ฌํ ๋ฌธ์ ๋ค์ ๋ฏธ๋ฆฌ ๋ค ํด๊ฒฐํด๋ ์ด๋ฏธ์ง ๋ก๋ฉ ๋ผ์ด๋ธ๋ฌ๋ฆฌ๋ฅผ ์ฌ์ฉํ๋ ์ด๋ค.


### 1. [Universal Image Loader(UIL)](https://github.com/nostra13/Android-Universal-Image-Loader)

- ์๋ 3๊ฐ์ ์ด๋ฏธ์ง ๋ก๋ฉ ๋ผ์ด๋ธ๋ฌ๋ฆฌ ์ด์ ์ ๊ฐ์ฅ ๋ง์ด ์ฐ์ด๋ ๋ผ์ด๋ธ๋ฌ.
- ๊ฐ์ฅ ๋ง์ด ์ฐ์๊ธฐ ๋๋ฌธ์ ๊ธฐ๋ฅ์ด๋ ์ค๋ฅ์ ๊ด๋ จ๋ ์๋ฃ๋ค์ ์ฝ๊ฒ ์ฐพ์๋ณผ ์ ์์.
- ์ฌ๋ฌ๊ฐ์ง Customํ๊ฒ ๋ณ๊ฒฝํ ์์๋๋ก ๋ง์ ์ต์์ ์ ๊ณตํฉ๋๋ค.

    #### โ Example Code
    ```java
    DisplayImageOptions options = new DisplayImageOptions.Builder() 
                                                        .cacheInMemory() 
                                                        .cacheOnDisc() 
                                                        ... 
                                                        .build(); 
    ImageLoader.getInstance().displayImage(imageUrl, imageView, options);
    ```


<br><br>



### 2. [Picasso](http://square.github.io/picasso/)

- UIL ์ดํ์ ์ต๊ทผ์ ๊ฐ์ฅ ๋๋ฆฌ ์ฐ์ด๊ณ ์๋ ์ด๋ฏธ์ง ๋ก๋ฉ ๋ผ์ด๋ธ๋ฌ๋ฆฌ.
- Okhttp, Retrofit ๋ฑ๋ฑ์ ์ ๋ชํ ๋ผ์ด๋ธ๋ฌ๋ฆฌ๋ฅผ ๋ง๋  ํ์ฌ์ธ Square์์ ๋ง๋ค์์.
- ๋ณ๋ค๋ฅธ ์ค์  ์์ ์์ด ์ง๊ด์ ์ผ๋ก ํจ์๋ฅผ ํธ์ถํด ์ฌ์ฉํ  ์ ์์ผ๋ฏ๋ก ํธ๋ฆฌ.

    #### โ Example Code

    ```java
    Picasso.with(context).load(imageUrl).resize(30, 30).into(imageView);
    ```


<br><br>



### 3. [Glide](https://github.com/bumptech/glide)

- Google์์ ๊ฐ๋ฐํด์ ๋ฐ๊ณ ์๋ volly์ดํ์ 2014๋์ ๊ณต๊ฐ๋ ๋ผ์ด๋ธ๋ฌ๋ฆฌ์๋๋ค.
- Bump์ฑ์ ๊ตฌ๊ธ์ด ์ธ์ํ๋ฉด์ bump์ฑ์์ ์ฌ์ฉํ๋ ์ด๋ฏธ์ง ๋ผ์ด๋ธ๋ฌ๋ฆฌ๋ฅผ ๊ณต๊ฐํ๊ฒ์ด ์ด Glide์๋๋ค๋ค.
- ๊ธฐ์กด์ Picasso์์ ์ฌ์ฉํ๋ ํจ์ ๋ฐฉ์๊ณผ ๊ฑฐ์ ๋น์ทํฉ๋๋ค(์ผ๋ถ ํจ์๋ฅผ ๋นผ๊ณ ๋ ๊ฑฐ์ ๋๊ฐ๋ค๊ณ  ๋ด๋ ์ข์ต๋๋ค.)
- ๋ค๋ฅธ ์ด๋ฏธ์ง ๋ก๋ฉ ๋ผ์ด๋ธ๋ฌ๋ฆฌ์๋ ์๋ ์ธ๋ค์ผ ๋ณด๊ธฐ, GIF ๋ก๋ฉ, ๋์์ ์คํธ ๋ณด๊ธฐ ๊ธฐ๋ฅ๊น์ง ์ง์ํฉ๋๋ค.

### 3-1. Gilde ์ฌ์ฉ๋ฐฉ๋ฒ

#### 1) Gradle ์ถ๊ฐ

```java
implementation 'com.github.bumptech.glide:glide:4.9.0'
annotationProcessor 'com.github.bumptech.glide:compiler:4.9.0'
```


#### 2) ์ฌ์ฉ๋ฒ

```java
Glide.with(this).load("http://www.selphone.co.kr/homepage/img/team/3.jpg").into(imageView);
```


#### 3) ์ ์ฉํ ํจ์

- override()   
: ์ง์ ํ ์ด๋ฏธ์ง์ ํฌ๊ธฐ๋งํผ๋ง ๋ถ๋ฌ์ฌ์ ์์ต๋๋ค. ์ด๋ฅผ ํตํด ์ด๋ฏธ์ง ๋ก๋ฉ ์๋๋ฅผ ์ต์ ํ ํ ์์์ต๋๋ค.
  #### โ Example Code

    ```java
    Glide.with(this)
        .load("์ด๋ฏธ์ง url...")
        .override(์ด๋ฏธ์ง ์ฌ์ด์ฆ) // ex) override(600, 200)
        .into(imageView);
    ```


- placeholder()   
: ์ด๋ฏธ์ง๋ฅผ ๋ก๋ฉํ๋๋์ ์ฒ์์ ๋ณด์ฌ์ค placeholder์ด๋ฏธ์ง๋ฅผ ์ง์ ํ  ์ ์์ต๋๋ค.
  #### โ Example Code

    ```java
    Glide.with(this)
        .load("์ด๋ฏธ์ง url...")
        .placeholder(๋ก๋ฉ ์ด๋ฏธ์ง) // ex) placeholder(R.drawable.loading)
        .into(imageView)
    ```  
  
- error()   
: ์ด๋ฏธ์ง๋ก๋ฉ์ ์คํจํ์๊ฒฝ์ฐ ์คํจ ์ด๋ฏธ์ง๋ฅผ ์ง์ ํ  ์ ์์ต๋๋ค.
  #### โ Example Code

    ```java
    Glide.with(this)
        .load("์ด๋ฏธ์ง url...")
        .error(์คํจ ์ด๋ฏธ์ง) // ex) error(R.drawable.error)
        .into(imageView)
    ```  

- asGif()   
: ์ ์ ์ธ ์ด๋ฏธ์ง ๋ฟ๋ง ์๋๋ผ GIF๋ ๋ก๋ฉํ ์ ์์ต๋๋ค.
  #### โ Example Code

    ```java
    Glide.with(this)
        .load("์ด๋ฏธ์ง(GIF) url...")
        .into(imageView)
        .asGif()
    ```
  
- thumbnail()   
  : ์ง์ ํ % ๋น์จ ๋งํผ ๋ฏธ๋ฆฌ ์ด๋ฏธ์ง๋ฅผ ๊ฐ์ ธ์์ ๋ณด์ฌ์ค๋๋ค. 0.1f๋ก ์ง์ ํ๋ค๋ฉด ์ค์  ์ด๋ฏธ์ง ํฌ๊ธฐ์ค 10%๋ง ๋จผ์  ๊ฐ์ ธ์์ ํ๋ฆฟํ๊ฒ ๋ณด์ฌ์ค๋๋ค.


<br><br>



### 4. [Fresco](http://frescolib.org/index.html)

- facebook์์ ๊ณต๊ฐํ ์ด๋ฏธ์ง ๋ผ์ด๋ธ๋ฌ๋ฆฌ์๋๋ค.
- 4๊ฐ์ ๋ผ์ด๋ธ๋ฌ๋ฆฌ ์ค์์ ๊ฐ์ฅ ์ต๊ทผ์ ๊ณต๊ฐ๋จ. (2015.03)
- ๋ค๋ง, ๋น๊ต์  ์ต๊ทผ์ ๊ณต๊ฐ๋ ๋ผ์ด๋ธ๋ฌ๋ฆฌ๋ผ์ ๋ ํผ๋ฐ์ค๋ ์ ๊ณ  Fresco์ ImageView๋ฅผ ์ฌ์ฉํด์ ํ๋ค๋ ๊ฒ์ด ๋จ์ .   
     
    #### โ Example Code
    
    - layout
        ```xml
        <LinearLayout
        xmlns:android="http://schemas.android.com/apk/res/android"
        xmlns:fresco="http://schemas.android.com/apk/res-auto">
        
        <com.facebook.drawee.view.SimpleDraweeView
        android:id="@+id/my_image_view"
        android:layout_width="200dip"
        android:layout_height="200dip"
        fresco:placeholderImage="@drawable/my_drawable" />
        
        </LinearLayout>
        ```
    
    - view
        ```java
        Fresco.initialize(this);
        setContentView(R.layout.activity_main);
        
        SimpleDraweeView simpleDraweeView = (SimpleDraweeView)findViewById(R.id.my_image_view);
        simpleDraweeView.setImageURI(Uri.parse("http://www.url.com/image.png"));
        ```



<br><br>



### โ ๋ค๋ฅธ ๋ผ์ด๋ธ๋ฌ๋ฆฌ๋ค๊ณผ์ ์ฑ๋ฅ ๋น๊ต

![](../image/image-library-img1.png)

- ๋ฉ๋ชจ๋ฆฌ, ์๋ ๊ฐ์ ์ด 6์ฅ์ ์ด๋ฏธ์ง๋ฅผ ๋ฆฌ์คํธ๋ทฐ์ ๋์ฐ๋ ๋ฐฉ์์ผ๋ก 3ํ ์งํํ์ฌ ํ๊ท ๊ฐ์ผ๋ก ๊ณ์ฐ.
- ๋ฐ๋ณต ์คํฌ๋กค ๋ถ๋ถ์ 50์ฅ ์ ๋์ ์ด๋ฏธ์ง๋ฅผ ๋ฆฌ์คํธ๋ทฐ์ ๋์ ๊ณ  ๋ฉ๋ชจ๋ฆฌ๋ฅผ ์ ๋ฆฌํ๊ธฐ ์ง์  ์ต๋ ์ฌ์ฉ๋์ ๊ตฌํ ๊ฒ.






## โจ Reference โจ

- [https://gun0912.tistory.com/17](https://gun0912.tistory.com/17)
- [https://velog.io/@rjsdnqkr1/Glide-%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC-%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0-yuk1fmwzo1](https://velog.io/@rjsdnqkr1/Glide-%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC-%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0-yuk1fmwzo1)
