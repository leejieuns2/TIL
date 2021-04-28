## 📌 Retrofit2를 활용한 MultipartRequest 정리


### 1. Retrofit 통신을 위한 인터페이스 구현
```java
public interface RetrofitService {

    final static String BASE_URL = "base_url";
    
    @Multipart
    @POST("post_url")
    Call<String> postImage(@Part MultipartBody.Part file);
}
```
 
<br>

### 2. 통신 메소드 구현
```java
public class RetrofitClient {

    private RetrofitService retrofitService;
    public static String baseUrl = RetrofitService.BASE_URL;
    private static Retrofit retrofit;

    private static class SingletonHolder {
        private static RetrofitClient INSTANCE = new RetrofitClient();
    }

    public static RetrofitClient getInstance() {
        return SingletonHolder.INSTANCE;
    }

    private RetrofitClient() {
        Gson gson = new GsonBuilder().setLenient().create();

        OkHttpClient.Builder builder = new OkHttpClient.Builder();

        ...

        OkHttpClient client = builder.build();
        retrofit = new Retrofit.Builder()
                .baseUrl(baseUrl)
                .client(client)
                .addConverterFactory(GsonConverterFactory.create(gson))
                .addCallAdapterFactory(RxJavaCallAdapterFactory.create())
                .build();
    }

    public RetrofitService createBaseApi() {
        retrofitService = create(RetrofitService.class);
        return this;
    }

    public <T> T create(final Class<T> service) {
        if (service == null) {
            throw new RuntimeException("Api service is null!");
        }
        return retrofit.create(service);
    }

    // RetrofitService에서 정의한 postImage 메소드 구현
    public String postImage(MultipartBody.Part file) throws IOException {
        Response<String> response = retrofitService.postImage(file).execute();
        return response.body();
    }
}
```

<br>

### 3. 구현한 Retrofit 통신 메소드 사용해 파일 전송하기
```java
public class CameraActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_camera);

        ...

        // 사진 확인 후 전송 버튼 클릭
        btnSendImg = findViewById(R.id.btnSendImg);
        btnSendImg.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ...
                NThread thread = new NThread(photoFile);
                thread.start();
                ...
            }
        });
    }
    //안드로이드 최근 버전에서는 네트워크 통신시에 반드시 스레드를 요구한다.
    class NThread extends Thread{

        File file;
        public NThread(File file) {
            this.file = file;
        }

        @Override
        public void run() {
            try {
                // Upload file
                uploadFile(file);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    
    public void uploadFile(File file) throws IOException {

        // Uri 타입의 파일경로를 가지는 RequestBody 객체 생성
        RequestBody fileBody = RequestBody.create(MediaType.parse("multipart/form-data"), file);

        // RequestBody로 Multipart.Part 객체 생성
        MultipartBody.Part filePart = MultipartBody.Part.createFormData(file.getName(), file.getName(), fileBody);
        Log.d(Tag, "header : " + filePart.headers().toString());

        RetrofitClient retrofitClient = RetrofitClient.getInstance().createBaseApi();
        String rslt_file = retrofitClient.postImage(filePart);
        Log.d(Tag, "file rslt : " + rslt_file);
    }
}
```

## ✨ Reference ✨

- [https://g-song-ii.tistory.com/11](https://g-song-ii.tistory.com/11)
- [https://k9327.tistory.com/5](https://k9327.tistory.com/5)
- [https://privatedevelopnote.tistory.com/18](https://privatedevelopnote.tistory.com/18)
- [https://hun-developer.tistory.com/8](https://hun-developer.tistory.com/8)
- [https://soooprmx.com/archives/9626](https://soooprmx.com/archives/9626)