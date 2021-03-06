
## ๐ thymeleaf ์ฌ์ฉํ๊ธฐ

<br>

### Thymeleaf ๋?
- spring ๊ธฐ๋ฐ ์น ์ ํ๋ฆฌ์ผ์ด์์ view์์ html, xml, javascript, css, text ์ฒ๋ฆฌ ํ ์น ๋ธ๋ผ์ฐ์ ์ ํ์ํ  ๋ ์ด์ฉ๋๋ ํํ๋ฆฟ ์์ง์ ์ผ์ข.
- JSP๋ณด๋ค ๋น ๋ฅด๋ค๋ ์ฅ์ ์ด ์์ผ๋ฉฐ, spring boot์ ๊ฐ์ด ๋ง์ด ์ฌ์ฉํจ.


<br>


### (1) thymeleaf ๊ธฐ์ด ์ค์ ํ๊ธฐ - build.gradle

```java
dependencies {
    implementation 'org.springframework.boot:spring-boot-starter-thymeleaf'
    implementation 'org.springframework.boot:spring-boot-starter-web'
}
```



<br>


### (2) src/main/resources/templates ์ html ํ์ผ ์ถ๊ฐ

![](../image/thymeleaf-img1.png)
- src/main/resources/static ์ html ํ์ผ ๊ด๋ จ css/js/img ํ์ผ ์ถ๊ฐ


<br>


### (3) src/main/java/ํ๋ก์ ํธ ํจํค์ง/config/MvcConfiguration ์์ฑ

![](../image/thymeleaf-img2.png)
- ์ฒ์์ MvcConfiguration ์ค์  ์์ด ๊ทธ๋ฅ ์คํํ๋๋ฐ, ํ์ด์ง ์ฐ๊ฒฐ์ด ์๋๊ณ  ์์ ํ๋ฉด๊ณผ ๊ฐ์ ์๋ฌ ํ์ด์ง(Whitelabel Error Page) ๋ง ๋ ์ ์ด๋ค ๋ถ๋ถ์ด ๋ฌธ์ ์ธ์ง ์ฐพ์๋ณด๋ ๊ธฐ์กด์๋ static ํ์ผ๋ค์์๋ง ์ ์  ํ์ผ(html)๋ค์ ๋ถ๋ฌ์ค๊ธฐ ๋๋ฌธ์ MvcConfiguration ํด๋์ค๋ฅผ ์์ฑํด templates ํ์ผ์์๋ ๋ถ๋ฌ์ฌ ์ ์๋๋ก ๊ด๋ จ ์ค์ ์ ๋ณ๊ฒฝ ํด์ฃผ์ด์ผ ํ๋ค๋ ๊ฒ์ ์๊ฒ๋์๋ค.
- MvcConfiguration Example Code

    ```java
    import org.springframework.context.annotation.Configuration;
    import org.springframework.http.CacheControl;
    import org.springframework.web.servlet.config.annotation.ResourceHandlerRegistry;
    import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;
    
    import java.util.concurrent.TimeUnit;
    
    @Configuration
    public class MvcConfiguration implements WebMvcConfigurer {
    
        @Override
        public void addResourceHandlers(final ResourceHandlerRegistry registry) {
            registry.addResourceHandler("/**")
                    .addResourceLocations("classpath:/templates/", "classpath:/static/")
                    .setCacheControl(CacheControl.maxAge(10, TimeUnit.MINUTES));
        }
    }
    
    ```



<br>

### (4) html ํ๊ทธ์ thymeleaf ์ค์  (view๋ก ์ฌ์ฉํ  html ํ์ผ์ ์ ๋ถ ์ค์ ํด์ฃผ์ด์ผ ํจ)
```html
<html xmlns:th="http://www.thymeleaf.org">
```


<br>


### (5) ์ฌ์ฉํ  static ํ์ผ๋ค์ thymeleaf ํ๊ทธ๋ฅผ ์ด์ฉํด ์ฐ๊ฒฐ
```html
<link th:href="@{/css/style.css}" rel="stylesheet">
```


<br>


### (6) Controller class ์์ฑ ๋ฐ View Mapping

```java
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class IndexController {
    @GetMapping("/index")
    public String index() {
        return "index";
    }
}
```

- index.html์ mappingํ ์์ class

<br>


### (7) ์คํ



<br><br><br>




## ๐ Thymeleaf๋ก Layout ์ค๋ณต ๊ด๋ฆฌํ๊ธฐ


<br>


### โ Layout ์ค๋ณต ์ฝ๋๋ฅผ ๋ถ๋ฆฌํ๋๊ฒ ํธ๋ฆฌํ ์ด์ ?
1. ์ฝ๋์ ๋ถํ์ํ ์ค๋ณต ์ ๊ฑฐ๋ก ๋ฑ ํต์ฌ ์ฝ๋๋ง ํ์ธํ  ์ ์์.
2. ์ ์ง๋ณด์์ ์ฉ์ด -> ๋ถ๋ฆฌ๋ ์ฝ๋๋ง ์์ ํ๋ฉด ๋ชจ๋  ํ์ด์ง์ ์ ์ฉ๋จ.


<br>


### Thymeleaf ํํ๋ฆฟ ์์ง์ ์ฌ์ฉํ ๋ ์ด์์ ์ธํํ๊ธฐ 

<br>

### 1. build.gradle์ dependency ์ฝ๋ ์ถ๊ฐ

```java
dependencies {
        // https://mvnrepository.com/artifact/nz.net.ultraq.thymeleaf/thymeleaf-layout-dialect
        implementation group: 'nz.net.ultraq.thymeleaf', name: 'thymeleaf-layout-dialect', version: '2.5.2'
}
```

- [url ์ฐธ๊ณ ](mvnrepository.com/artifact/nz.net.ultraq.thymeleaf/thymeleaf-layout-dialect/2.5.2)


<br>


### 2. ๊ณตํต ๋ถ๋ถ layout ํํ๋ฆฟ ๋ง๋ค๊ธฐ (src/main/resources/templates/fragments)


![](../image/thymeleaf-img3.png)


<br>


### 2-1. header.html (header ๋ถ๋ถ๋ง์ ์์ฑํ ์ฝ๋ ํ์ผ)

```html
<!DOCTYPE html>
<html lang="ko" xmlns:th="http://www.thymeleaf.org">

    <div th:fragment="headerFragment" class="header navbar-fixed-top">
		 <!--header ๋ถ๋ถ code -->        
    </div>

</html>
```


<br>


### 2-2. footer.html (footer ๋ถ๋ถ๋ง์ ์์ฑํ ์ฝ๋ ํ์ผ)

```html
<!DOCTYPE html>
<html lang="ko" xmlns:th="http://www.thymeleaf.org">

    <div th:fragment="footerFragment" class="header navbar-fixed-top">
		 <!--footer ๋ถ๋ถ code -->        
    </div>

</html>
```

<br>


### 2-3. config.html (๊ณตํต์ผ๋ก ์ฌ์ฉํ  css, js ํ์ผ ๋ฑ์ ์ ์ธ ์ฝ๋๋ฅผ ๋ชจ์ ํ์ผ)

```html
<!DOCTYPE html>
<html lang="ko" xmlns:th="http://www.thymeleaf.org">
    <!-- configFragment -->
    <th:block th:fragment="configFragment">
        <!-- Style ์์ -->
        <link th:href="@{/css/style.css}" rel="stylesheet">

        <!-- Javascript file ์์ -->
        <script th:src="@{/js/file.js}"></script>
    </th:block>
</html>
```

<br>


### 2-4. layout.html (์ ์ฒด์ ์ธ ํ์ ์์ฑํ ์ฝ๋ ํ์ผ)

```html
<!DOCTYPE html>
 <!-- layout ๊ด๋ จ namespace ์ถ๊ฐ ์ ์ธ -->
    <html lang="ko"
      xmlns:th="http://www.thymeleaf.org"
      xmlns:layout="http://www.ultraq.net.nz/thymeleaf/layout">
    <head>
        <meta charset="utf-8">

        <!-- config.html -->
        <th:block th:replace="fragments/config::configFragment" ></th:block>
    </head>
	
    	<!-- header.html -->
    <header th:replace="fragments/header::headerFragment"></header>

	<!-- ๊ณตํต์ ์ด์ง ์์ ๋ถ๋ถ์ด ๋ค์ด๊ฐ๋ ๋ถ๋ถ -->
    <body layout:fragment="content"></body>

	<!-- footer.html -->
    <footer th:replace="fragments/footer::footerFragment"></footer>
</html>
```

<br>


### 3. ๋ ์ด์์ ์ ์ฉ ( ๊ฐ๋ณ ํ์ผ์ 2๋ฒ์ ์์ฑํ ํํ๋ฆฟ ์ ์ฉํ๊ธฐ ) ex) index.html

```html
<!DOCTYPE html>
<!-- ๊ด๋ จ Namespace ์ ์ธ ๋ฐ layout:decorate ์ถ๊ฐ -->
<html lang="en"
      xmlns:th="http://www.thymeleaf.org"
      xmlns:layout="http://www.ultraq.net.nz/thymeleaf/layout"
      layout:decorate="~{fragments/layout}">
    <head>
        <!-- layout.html ์ ๋ค์ด๊ฐ head ๋ถ๋ถ์ ์ ์ธํ๊ณ  ๊ฐ๋ณ ํ์ผ์๋ง ์ ์ฉ๋๋ head ๋ถ๋ถ ์ถ๊ฐ -->
        <title>Page Title</title>

        <!-- ํ์ํ๋ค๋ฉด ๊ฐ๋ณ ํ์ผ์ ์ฌ์ฉ๋  css/js ์ ์ธ  -->
    </head>

    <!-- layout.html์ ์ ์ํ main page ๋ถ๋ถ -->
    <body layout:fragment="content">
        <!-- code -->
    </body>
</html>
```


<br><br>



## โจ Reference โจ

[bottom-to-top.tistory.com/38](bottom-to-top.tistory.com/38)
[blog.jiniworld.me/44](blog.jiniworld.me/44)
[bamdule.tistory.com/33](bamdule.tistory.com/33)