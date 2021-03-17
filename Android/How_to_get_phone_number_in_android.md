## 📌 안드로이드 기기 정보 가져오기

### 1. AndroidManifest.xml 에 Permission 추가

```xml
<uses-permission android:name="android.permission.READ_PHONE_STATE"/>
```

### 2. Method 추가

```java
@SuppressLint("MissingPermission")
public String getPhoneNumber() {
    TelephonyManager telephony = (TelephonyManager) getSystemService(Context.TELEPHONY_SERVICE);
    String phoneNumber = "";

    try {
        if (telephony.getLine1Number() != null) {
            phoneNumber = telephony.getLine1Number();
        } else {
            if (telephony.getSimSerialNumber() != null) {
                phoneNumber = telephony.getSimSerialNumber();
            }
        }
    } catch (Exception e) {
        e.printStackTrace();
    }

    if (phoneNumber.startsWith("+82")) {
        phoneNumber = phoneNumber.replace("+82", "0"); // +8210xxxxyyyy 로 시작되는 번호
    }

    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
        phoneNumber = PhoneNumberUtils.formatNumber(phoneNumber, Locale.getDefault().getCountry());
    } else {
        phoneNumber = PhoneNumberUtils.formatNumber(phoneNumber);
    }

    return phoneNumber;
}
```

- 함수 자체의 반환값으로는 000-0000-0000 형식의 데이터를 받아오는 것을 알 수 있음. 추가적인 포맷 변환은 코드 수정 필요.


## ✨ Reference ✨

- [https://devjo9.tistory.com/m/20](https://devjo9.tistory.com/m/20)