## 📌 MalformedJsonException 원인 및 해결방법 정리

### Error Log
```
D/CameraActivity: header : Content-Disposition: form-data; name="((filename))"; filename="((filename))" ---- 1.
D/OkHttp: --> POST http://((HTTP url))
Content-Type: multipart/form-data; boundary=ca2f4314-1b12-4bbe-9a2b-87d60408fba6
D/OkHttp: Content-Length: 2876511
D/OkHttp: --ca2f4314-1b12-4bbe-9a2b-87d60408fba6
Content-Disposition: form-data; name="((filename))"; filename="((filename))"
Content-Type: multipart/form-data
Content-Length: 2876203
((binary data for image))
D/OkHttp: <-- 200 OK http://((HTTP url)) (3516ms) ---- 2
Server: Apache-Coyote/1.1
Set-Cookie: JSESSIONID=((sessionId)); Path=/fu00/; HttpOnly
Content-Type: text/html;charset=UTF-8
Content-Length: 90
Date: Thu, 18 Mar 2021 17:37:08 GMT
D/OkHttp: \MOBILEDATA\((filename)).png ---- 3.
<-- END HTTP (90-byte body)
W/System.err: com.google.gson.stream.MalformedJsonException: Expected value at line 10 column 1 path $
at com.google.gson.stream.JsonReader.syntaxError(JsonReader.java:1568)
at com.google.gson.stream.JsonReader.doPeek(JsonReader.java:590)
at com.google.gson.stream.JsonReader.peek(JsonReader.java:425)
at com.google.gson.internal.bind.TypeAdapters$16.read(TypeAdapters.java:392)
at com.google.gson.internal.bind.TypeAdapters$16.read(TypeAdapters.java:389)
at retrofit2.converter.gson.GsonResponseBodyConverter.convert(GsonResponseBodyConverter.java:39)
at retrofit2.converter.gson.GsonResponseBodyConverter.convert(GsonResponseBodyConverter.java:27)
at retrofit2.ServiceMethod.toResponse(ServiceMethod.java:122)
at retrofit2.OkHttpCall.parseResponse(OkHttpCall.java:217)
at retrofit2.OkHttpCall.execute(OkHttpCall.java:180)
at retrofit2.ExecutorCallAdapterFactory$ExecutorCallbackCall.execute(ExecutorCallAdapterFactory.java:91)
at com.project.service.RetrofitClient.postImage(RetrofitClient.java:99)
at com.project.ui.camera.CameraActivity.uploadFile(CameraActivity.java:217)
at com.project.ui.camera.CameraActivity$NThread.upload(CameraActivity.java:202)
W/System.err:     at com.project.ui.camera.CameraActivity$NThread.run(CameraActivity.java:186)
```

- 1번과 2번 문장을 통해 Http 통신은 잘 되는 것을 알 수 있었으나, Response를 받아오는 과정에서 MalformedJsonException 에러가 발생하는 것을 알 수 있었음.
- MalformedJsonException은 Json 포맷에 어긋날 때 발생하는 에러로 추정.
- [https://jsonformatter.curiousconcept.com/](https://jsonformatter.curiousconcept.com/) 페이지에서 json 포맷 유효성 검사를 통해 Response의 값이 Json으로 넘어올 때 Json 포맷에서 어긋나 에러가 발생하는 것을 알 수 있었음.
- 서버에서 response를 전달할때 response에 유효하지 않은 데이터를 삭제해 전송함으로써 에러를 해결할 수 있었음.

<br>

## ✨ Reference ✨

- [https://hashcode.co.kr/questions/2188/retrofit19-%EC%A7%88%EB%AC%B8%EB%93%9C%EB%A6%BD%EB%8B%88%EB%8B%A4](https://hashcode.co.kr/questions/2188/retrofit19-%EC%A7%88%EB%AC%B8%EB%93%9C%EB%A6%BD%EB%8B%88%EB%8B%A4)