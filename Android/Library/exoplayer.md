
## 📌 Exoplayer Library

- [Open Source URL](https://github.com/google/ExoPlayer) / [Developer Site](https://exoplayer.dev/hello-world.html)
   

- ExoPlayer는 안드로이드용 오픈소스 미디어 재생 라이브러리다.
- 원래는, YouTube나 Google Play Movies와 같은 구글의 Android Application을 위해 개발 되었으나 2014년 open source로 공개 되었다.
- ExoPlayer의 표준 오디오 및 비디오 구성 요소는 Android 4.1(API Level 16)에서 출시된 Android’s MediaCodec API를 기반으로 한다.
- DASH 콘텐츠를 재생하도록 설계되었으며, 출시 이후 다양한 기술과 formats을 지원합니다.

### Exoplayer의 장점

- 젤리빈(API 16~18) 이상에서 동작 되기 때문에 거의 모든 기기에서 호환이 됩니다.
- MediaPlayer 보다 안정적이고 유연합니다. (커스텀 하기 좋습니다)
- MediaPlayer에서 지원하지 않는 기능들과 편하게 커스텀하고 확장할 수 있기 때문에 좋다는 것이다.
- ExoPlayer는 .NET에서 지원하지 않는 DASH (Dynamic Adaptive Streaming over HTTP), HLS (HTTP Live Streaming), SmoothStreaming 및 Common Encryption과 같은 기능을 지원합니다 `MediaPlayer`.
- ExoPlayer는 모듈 식 디자인이므로 쉽게 확장하고 사용자 지정할 수 있습니다.
- Android의 주요 비디오 스트리밍 거대 기업은 기능과 유연성 때문에 주로 Exoplayer에 의존합니다. ExoPlayer는 Android YouTube, Netflix, Prime, HotStar 용 Amazon 미디어 플레이어 및 기타 인기 있고 강력한 앱에서 실행되는 비디오 플레이어입니다.
- 좋은 문서와 튜토리얼.
- 무료입니다!

### Exoplayer 사용시 주의사항

1. ExoPlayer는 Android 4.1 (API 레벨 16)에서 나온 Android의 MediaCodec API를 기반으로 구축되었습니다. 따라서 Exoplayer를 통합하려면 앱의 최소 API 버전을 API 16으로 설정해야합니다.
2. 사용할 모듈만 의존성 추가하기
    - 사용 가능한 라이브러리 모듈은 다음과 같습니다.
    - `exoplayer-core`: 핵심 기능 (필수).
    - `exoplayer-dash`: DASH 콘텐츠 지원.
    - `exoplayer-hls`: HLS 콘텐츠 지원.
    - `exoplayer-smoothstreaming`: SmoothStreaming 콘텐츠 지원.
    - `exoplayer-ui`: ExoPlayer와 함께 사용할 UI 구성 요소 및 리소스입니다.

  또한 `repositories` 프로젝트 수준 build.gradle 파일 의 섹션에 JCenter 및 Google을 추가했는지 확인 하세요. 새 버전에서는 기본적으로 추가됩니다.


## ✨ Reference ✨

[](https://medium.com/@sunminlee89/%EB%AC%B4%EC%9E%91%EC%A0%95-%EC%95%B1%EB%A7%8C%EB%93%A4%EA%B8%B0-6-exoplayer%EB%A1%9C-%EA%B0%84%EB%8B%A8%ED%95%9C-%EB%AE%A4%EC%A7%81-%ED%94%8C%EB%A0%88%EC%9D%B4%EC%96%B4%EB%A5%BC-%EB%A7%8C%EB%93%A4%EC%96%B4%EB%B3%B4%EC%9E%90-46e6b2594601)

[Android ExoPlayer : YouTube처럼 앱에서 동영상 재생](https://ichi.pro/ko/android-exoplayer-youtubecheoleom-aeb-eseo-dong-yeongsang-jaesaeng-79612915823511)