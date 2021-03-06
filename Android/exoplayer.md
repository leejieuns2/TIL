
## ๐ Exoplayer Library

- [Open Source URL](https://github.com/google/ExoPlayer) / [Developer Site](https://exoplayer.dev/hello-world.html)
   

- ExoPlayer๋ ์๋๋ก์ด๋์ฉ ์คํ์์ค ๋ฏธ๋์ด ์ฌ์ ๋ผ์ด๋ธ๋ฌ๋ฆฌ๋ค.
- ์๋๋, YouTube๋ Google Play Movies์ ๊ฐ์ ๊ตฌ๊ธ์ Android Application์ ์ํด ๊ฐ๋ฐ ๋์์ผ๋ 2014๋ open source๋ก ๊ณต๊ฐ ๋์๋ค.
- ExoPlayer์ ํ์ค ์ค๋์ค ๋ฐ ๋น๋์ค ๊ตฌ์ฑ ์์๋ Android 4.1(API Level 16)์์ ์ถ์๋ Androidโs MediaCodec API๋ฅผ ๊ธฐ๋ฐ์ผ๋ก ํ๋ค.
- DASH ์ฝํ์ธ ๋ฅผ ์ฌ์ํ๋๋ก ์ค๊ณ๋์์ผ๋ฉฐ, ์ถ์ ์ดํ ๋ค์ํ ๊ธฐ์ ๊ณผ formats์ ์ง์ํฉ๋๋ค.

### Exoplayer์ ์ฅ์ 

- ์ ค๋ฆฌ๋น(API 16~18) ์ด์์์ ๋์ ๋๊ธฐ ๋๋ฌธ์ ๊ฑฐ์ ๋ชจ๋  ๊ธฐ๊ธฐ์์ ํธํ์ด ๋ฉ๋๋ค.
- MediaPlayer ๋ณด๋ค ์์ ์ ์ด๊ณ  ์ ์ฐํฉ๋๋ค. (์ปค์คํ ํ๊ธฐ ์ข์ต๋๋ค)
- MediaPlayer์์ ์ง์ํ์ง ์๋ ๊ธฐ๋ฅ๋ค๊ณผ ํธํ๊ฒ ์ปค์คํํ๊ณ  ํ์ฅํ  ์ ์๊ธฐ ๋๋ฌธ์ ์ข๋ค๋ ๊ฒ์ด๋ค.
- ExoPlayer๋ .NET์์ ์ง์ํ์ง ์๋ DASH (Dynamic Adaptive Streaming over HTTP), HLS (HTTP Live Streaming), SmoothStreaming ๋ฐ Common Encryption๊ณผ ๊ฐ์ ๊ธฐ๋ฅ์ ์ง์ํฉ๋๋คย `MediaPlayer`.
- ExoPlayer๋ ๋ชจ๋ ์ ๋์์ธ์ด๋ฏ๋ก ์ฝ๊ฒ ํ์ฅํ๊ณ  ์ฌ์ฉ์ ์ง์ ํ  ์ ์์ต๋๋ค.
- Android์ ์ฃผ์ ๋น๋์ค ์คํธ๋ฆฌ๋ฐ ๊ฑฐ๋ ๊ธฐ์์ ๊ธฐ๋ฅ๊ณผ ์ ์ฐ์ฑ ๋๋ฌธ์ ์ฃผ๋ก Exoplayer์ ์์กดํฉ๋๋ค. ExoPlayer๋ Android YouTube, Netflix, Prime, HotStar ์ฉ Amazon ๋ฏธ๋์ด ํ๋ ์ด์ด ๋ฐ ๊ธฐํ ์ธ๊ธฐ ์๊ณ  ๊ฐ๋ ฅํ ์ฑ์์ ์คํ๋๋ ๋น๋์ค ํ๋ ์ด์ด์๋๋ค.
- ์ข์ ๋ฌธ์์ ํํ ๋ฆฌ์ผ.
- ๋ฌด๋ฃ์๋๋ค!

### Exoplayer ์ฌ์ฉ์ ์ฃผ์์ฌํญ

1. ExoPlayer๋ Android 4.1 (API ๋ ๋ฒจ 16)์์ ๋์จ Android์ MediaCodec API๋ฅผ ๊ธฐ๋ฐ์ผ๋ก ๊ตฌ์ถ๋์์ต๋๋ค. ๋ฐ๋ผ์ Exoplayer๋ฅผ ํตํฉํ๋ ค๋ฉด ์ฑ์ ์ต์ API ๋ฒ์ ์ API 16์ผ๋ก ์ค์ ํด์ผํฉ๋๋ค.
2. ์ฌ์ฉํ  ๋ชจ๋๋ง ์์กด์ฑ ์ถ๊ฐํ๊ธฐ
    - ์ฌ์ฉ ๊ฐ๋ฅํ ๋ผ์ด๋ธ๋ฌ๋ฆฌ ๋ชจ๋์ ๋ค์๊ณผ ๊ฐ์ต๋๋ค.
    - `exoplayer-core`: ํต์ฌ ๊ธฐ๋ฅ (ํ์).
    - `exoplayer-dash`: DASH ์ฝํ์ธ  ์ง์.
    - `exoplayer-hls`: HLS ์ฝํ์ธ  ์ง์.
    - `exoplayer-smoothstreaming`: SmoothStreaming ์ฝํ์ธ  ์ง์.
    - `exoplayer-ui`: ExoPlayer์ ํจ๊ป ์ฌ์ฉํ  UI ๊ตฌ์ฑ ์์ ๋ฐ ๋ฆฌ์์ค์๋๋ค.

  ๋ํ `repositories` ํ๋ก์ ํธ ์์ค build.gradle ํ์ผ ์ ์น์์ JCenter ๋ฐ Google์ ์ถ๊ฐํ๋์ง ํ์ธ ํ์ธ์. ์ ๋ฒ์ ์์๋ ๊ธฐ๋ณธ์ ์ผ๋ก ์ถ๊ฐ๋ฉ๋๋ค.


## โจ Reference โจ

[](https://medium.com/@sunminlee89/%EB%AC%B4%EC%9E%91%EC%A0%95-%EC%95%B1%EB%A7%8C%EB%93%A4%EA%B8%B0-6-exoplayer%EB%A1%9C-%EA%B0%84%EB%8B%A8%ED%95%9C-%EB%AE%A4%EC%A7%81-%ED%94%8C%EB%A0%88%EC%9D%B4%EC%96%B4%EB%A5%BC-%EB%A7%8C%EB%93%A4%EC%96%B4%EB%B3%B4%EC%9E%90-46e6b2594601)

[Android ExoPlayer : YouTube์ฒ๋ผ ์ฑ์์ ๋์์ ์ฌ์](https://ichi.pro/ko/android-exoplayer-youtubecheoleom-aeb-eseo-dong-yeongsang-jaesaeng-79612915823511)