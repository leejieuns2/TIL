## 📌 안드로이드 기기 정보 가져오기

### 1. AndroidManifest.xml 에 Permission 추가

```xml
<uses-permission android:name="android.permission.READ_PHONE_STATE"/>
```

### 2. Method 추가

```java
public String getPhoneNumber() {
    String phoneNumber = "";
    TelephonyManager telephonyManager = (TelephonyManager) getSystemService(Context.TELEPHONY_SERVICE);
    try {
        // permission check
        if (ActivityCompat.checkSelfPermission(this, Manifest.permission.READ_SMS) != PackageManager.PERMISSION_GRANTED
            && ActivityCompat.checkSelfPermission(this, Manifest.permission.READ_PHONE_NUMBERS) != PackageManager.PERMISSION_GRANTED
            && ActivityCompat.checkSelfPermission(this, Manifest.permission.READ_PHONE_STATE) != PackageManager.PERMISSION_GRANTED) {
        } else {
            checkPermissions();
        }
        String tmpPhoneNumber = telephonyManager.getLine1Number();
        phoneNumber = tmpPhoneNumber.replace("+82", "0");
    } catch (Exception e) {
        phoneNumber = "error";
        e.printStackTrace();
    }

    return phoneNumber;
}
```

- 함수 자체의 반환값으로는 000-0000-0000 형식의 데이터를 받아오는 것을 알 수 있음. 추가적인 포맷 변환은 코드 수정 필요.
- 별도의 permission check 메소드가 필요. 

## ✨ Reference ✨

- [https://devjo9.tistory.com/m/20](https://devjo9.tistory.com/m/20)