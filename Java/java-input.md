
# ๐ ์๋ฐ ์๋ ฅ๋ฐฉ๋ฒ ๋น๊ต (Scanner, BufferedReader)

## 1. Scanner

###  โ Example code
   ```java
    import java.util.Scanner;
    
    public class Practice {
        public static void main(String[] args) {
            Scanner scan = new Scanner(System.in);
            String input = scan.next();
            String inputLine = scan.nextLine();
            ...
        }
    }
   ```

- java.util ํจํค์ง๋ฅผ importํด์ผ ์ฌ์ฉ์ด ๊ฐ๋ฅํ๋ค.
- Scanner ๊ฐ์ฒด๋ฅผ ์ ์ธํ ํ Scanner ํด๋์ค์ ๋ด์ฅ ํจ์๋ฅผ ์ฌ์ฉํด ๋ฐ์ดํธ ๋จ์๋ก ์๋ ฅ๊ฐ์ ๋ฐ์์จ๋ค.
- next() : ๊ณต๋ฐฑ ์ด์ ๊น์ง์ ๋ฌธ์๋ฅผ ์๋ ฅ๋ฐ๋๋ค.
- nextLine() : ๊ฐํ ์ ๊น์ง์ ๋ฌธ์์ด ์ ์ฒด๋ฅผ ์๋ ฅ๋ฐ๋๋ค. (ํ ์ค์ฉ ์๋ ฅ๋ฐ์)
   

<br>

> ์ฅ์ 

- ์ ์ธ ๋ฐฉ์์ด ๋น๊ต์  ์ฝ๊ณ  ๊ฐ๋จํ๋ค.
- String ๋ฟ๋ง ์๋๋ผ int, double, float ๋ฑ์ ๋ค์ํ ์๋ฃํ์ผ๋ก ์๋ ฅ๊ฐ์ ์ ์ฅํ  ์ ์๋ค.
  ( nextInt(), nextDouble(), nextFloat() ๋ฑ์ Scanner ๋ด์ฅ ํจ์๋ฅผ ์ฌ์ฉํ  ์ ์์ด ํธ๋ฆฌ)



> ๋จ์ 

- ๋ฒํผ ๊ธธ์ด๊ฐ 1024๋ก ํ์ ์ ์ด๋ค.
- ํ๋ฒ์ ๋ง์ ์๋ ฅ๊ฐ์ ์ ์ฅํ๋๋ฐ์ ๋ง์ ์๊ฐ์ด ์์๋ผ ๋นํจ์จ์ ์ด๋ค.


<br><br>


## 2-1. BufferedReader

###  โ Example code
  
    ```java
    import java.io.BufferedReader;
    import java.io.IOException;
    import java.io.InputStreamReader;
    
    public class Practice {
    
        public static void main(String[] args) throws IOException {
    
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String input = br.readLine();
            ...
        }
    }
    ```

- java.io ํจํค์ง๋ฅผ importํด์ผ ์ฌ์ฉ ๊ฐ๋ฅํ๋ค.
- BufferedReader ๊ฐ์ฒด๋ฅผ ์์ฑํ๊ณ , ๊ฐ์ฒด์ ๋งค๊ฐ๋ณ์๋ก InputStreamReader ๊ฐ์ฒด๋ฅผ ๋ฐ์ ์ฌ์ฉํ๋ค.
- BufferedReader ํด๋์ค์ ๋ด์ฅ ํจ์์ธ readLine()์ ํธ์ถํ์ฌ ์ค ๋จ์๋ก ์๋ ฅ๊ฐ์ ๋ฐ์์จ๋ค.


<br>


> ์ฅ์ 

- ๋ฒํผ์ ๊ธธ์ด๊ฐ 8192๋ก, Scanner์ ๋นํด ์๋์ ์ผ๋ก ํฌ๋ค.
- ๋ง์ ๋ฐ์ดํฐ๋ฅผ ํ๋ฒ์ ๋ฐ์์ค๊ณ ์ ํ  ๋ ์ฑ๋ฅ ์ ํจ์จ์ ์ด๋ค.



###  โ ํจ์จ์ ์ธ ์ด์ ?
- BufferedReader ํด๋์ค๊ฐ ๊ธฐ๋ณธ ์์ถ๋ ฅ ์คํธ๋ฆผ์ ๋ฒํผ ๊ธฐ๋ฅ์ ์ถ๊ฐํ ์คํธ๋ฆผ(Buffered Stream) ์ ์ฌ์ฉํด ์๋ ฅ๋ฐ๊ธฐ ๋๋ฌธ์ด๋ค. ์ด ๋๋ฌธ์ ์๋ ฅ๋ ๋ฐ์ดํฐ๊ฐ ๋ฐ๋ก ํ๋ก๊ทธ๋จ์ผ๋ก ์ ๋ฌ๋์ง ์๊ณ  ์ค๊ฐ์ ๋ฒํผ๋ง์ด ๋ ํ์ ์ ๋ฌ๋๋ฉฐ, ์ด๋ ์์คํ์ ๋ฐ์ดํฐ์ฒ๋ฆฌ์ ํจ์จ์ฑ์ ๋์ฌ์ค๋ค.


> ๋จ์ 

- Scanner๋ณด๋ค ์ฌ์ฉ ๋ฐฉ์์ด ๋ณต์กํ๋ค.
- ์๋ ฅ๊ฐ์ ๋ฌด์กฐ๊ฑด String์ผ๋ก๋ง ๋ฐ์ผ๋ฉฐ, ๋ค๋ฅธ ์๋ฃํ์ ์ฌ์ฉํ๊ณ  ์ถ์ ๋์๋ ๋ฌด์กฐ๊ฑด ๋ฐ์ดํฐ ํ์์ ์ถ๊ฐ ๋ณํ or ํ์ฑ ํด์ฃผ์ด์ผ ์ฌ์ฉํ  ์ ์๋ค.
- Scanner์ ๋ฌ๋ฆฌ ์์ฒด์ ์ผ๋ก IOException ์ฒ๋ฆฌ๋ฅผ ๋ณ๋๋ก ํด์ฃผ์ด์ผ ํ๋ค.
- ๊ฐํ(Enter)๋ฅผ ๊ธฐ์ค์ผ๋ก ์๋ ฅ์ ๋ฐ๊ธฐ ๋๋ฌธ์, ๊ณต๋ฐฑ์ ๊ธฐ์ค์ผ๋ก ๊ฐ์ ์๋ ฅ๋ฐ๋ ๊ฒฝ์ฐ ๋ณ๋์ ํ์ฑ์ด ํ์ํ๋ค.

  (2-2. StringTokenizer ์ฐธ๊ณ )


<br><br>


## 2-2. StringTokenizer

###  โ Example code

  ```java
  import java.io.BufferedReader;
  import java.io.IOException;
  import java.io.InputStreamReader;
  import java.util.StringTokenizer;
  
  public class Practice {
  
      public static void main(String[] args) throws IOException {
  
          BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
          String input = br.readLine();
          
          StringTokenizer st = new StringTokenizer(input);
          String input1 = st.nextToken();
          String input2 = st.nextToken();
          
          System.out.println("input : " + input);
          System.out.println("input1 : " + input1);
          System.out.println("input2 : " + input2);
      }
  }
  ```

- java.util ํจํค์ง๋ฅผ import ํด์ผ ์ฌ์ฉํ  ์ ์๋ค.
- StringTokenizer ํด๋์ค๋ 2-1. BufferedReader์ ๊ฐ์ด ์ฐ์ด๋ฉฐ, String.split()๊ณผ ๋น์ทํ ๊ธฐ๋ฅ์ ๊ฐ์ง๊ณ  ์๋ค.
- BufferedReader๋ก ํ ์ค์ ์๋ ฅ๋ฐ์์ ๋, ๋ง์ฝ ๊ณต๋ฐฑ์ ๊ธฐ์ค์ผ๋ก ์๋ ฅ๊ฐ์ ๋๋๊ณ  ์ถ์ผ๋ฉด StringTokenizer๋ฅผ ์ฌ์ฉํ์ฌ ํ์ฑํ๋ฉด ๋๋ค. nextToken() ํจ์๋ฅผ ์ฌ์ฉํ์ฌ String์ผ๋ก ๋ค์ ๊ณต๋ฐฑ ์  ๋ฌธ์์ด์ ์ ์ฅํ  ์ ์๋ค.


<br>

###  โ Example Result

  ![result-image](../image/input-java-img1.png)

- ์์ ์์ ์ฝ๋๋ฅผ ์คํํ ๊ฒฐ๊ณผ๋ก์จ, BufferedReader๋ก "hello world !!" ์ ์ฒด๋ฅผ input ๋ณ์์ ์ ์ฅํ ๋ค, ์ด๊ฒ์ StringTokenizer๋ก ๊ณต๋ฐฑ์ ๊ธฐ์ค์ผ๋ก ํ์ฑํด ์ถ๋ ฅํ ๊ฒ์ด๋ค.
- ์ฌ์ง์์ ์ ์ ์๋ ๊ฒ์ฒ๋ผ, nextToken() ํจ์๋ฅผ ์ฌ์ฉํด ๊ณต๋ฐฑ์ ๊ธฐ์ค์ผ๋ก ์๋ ฅ๊ฐ์ ๋๋์ด ์ ์ฅํ  ์ ์์ผ๋ฉฐ, "!!" ์ ๋ฌธ์์ด์ด ์๋ฆฐ ๊ฒ์ ๋ณด๋ค ํจ๊ณผ์ ์ผ๋ก ์ ์ ์๋ ๋ถ๋ถ์ด๋ค.