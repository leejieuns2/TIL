## 📍 컨테이너를 이미지로 만들기
- 컨테이너를 다른 컴퓨터 또는 서버로 복사하고 싶거나, 똑같은 컨테이너를 여러 개 만들고 싶다면 컨테이너를 이미지로 만드는 방법이 유용하다.
- 개발 단계에서 동일한 환경을 여러 개 복제할 수 있다는 면에서 알아두면 편리하다.

### 컨테이너를 이미지로 변환
- 기존 컨테이너를 복제하거나 이동해야 할 경우 편리하다.

```shell
$ docker commit [컨테이너_이름] [새로운_이미지_이름]
```

### Dockerfile 스크립트로 이미지 만들기
- Dockerfile 스크립트에는 토대가 될 이미지나 실행할 명령어 등을 기재한다.

```shell
$ docker build -t [생성할_이미지_이름] [재료_폴더_경로]

# dockerfile script example
$ vi dockerfile_example
FROM [이미지_이름]
COPY [원본_경로] [대상_경로]
RUN [리눅스_명령어]
```

### Dockerfile Instructions
- FROM
    - 생성할 이미지의 베이스가 될 이미지를 지정합니다. FROM 명령어는 Dockerfile을 작성할 때 반드시 한 번 이상 입력해야 함.
- RUN
    - 이미지를 만들기 위해 컨테이너 내부에서 실행할 명령어를 지정.
    - RUN 명령어에 "/bin/bash"를 같이 입력하면 /bin/bash 셸을 이용해 명령어를 실행할 수 있음.
- WORKDIR
    - 명령어를 실행할 디렉터리를 나타냅니다. 배시 쉘에서 cd 명령어를 입력하는 것과 같은 기능. 즉, 컨테이너 내부에서 작동.
    - RUN. CMD, ENTRYPOINT, ADD, COPY에 정의된 명령어를 실행하는 작업 디렉터리를 지정 가능.
- EXPOSE
    - Dockerfile의 빌드로 생성된 이미지에서 노출할 포트 설정.
      그러나 EXPOSE를 설정한 이미지로 컨테이너를 생성했다고 해서 반드시 이 포트가 호스트의 포트와 바인딩되는 것은 아니며, 단지 컨테이너의 80번 포트를 사용할 것임을 나타내는 것.
- ADD, COPY
    - COPY는 로컬 디렉터리에서 읽어 들인 컨텍스트로부터 이미지에 파일을 복사하는 역할을 합니다.
    - ADD는 외부 URL 및 tar 파일에서도 파일을 추가할 수 있다는 점이 다릅니다. (ADD보다 COPY 사용 권장)
- ENTRYPOINT, CMD
    - 둘 다 컨테이너를 실행할 때 실행할 명령어를 지정함. ENTRYPOINT는 강제 지정.
    - CMD는 컨테이너가 시작될 때마다 실행할 명령어를 설정하며, Dockerfile에서 한 번만 사용할 수 있습니다.
    - ENTRYPOINT, CMD는 역할 자체는 비슷하지만 서로 다른 역할을 담당.   
      둘 다 컨테이너가 시작될 때 수행할 명령을 지정한다는 점에서 같지만, entrypoint는 커맨드를 인자로 받아 사용할 수 있는 스크립트의 역할을 할 수 있다는 점에서 다릅니다.

### 실습 예시
```shell
# 컨테이너 생성
$ docker run --name apa000ex22 -d -p 8092:80 httpd
6a505784db330236fed447515768f6383163528aa8eae4fd77f9be6100fdc830

# 생성한 컨테이너로 이미지 생성
$ docker commit apa000ex22 ex22_original1
sha256:5c48352a6ca1d533503839ecd118967f3a33058de7c9517da73e9657e547db67

# 이미지 생성 확인
$ docker image ls
REPOSITORY       TAG       IMAGE ID       CREATED         SIZE
ex22_original1   latest    5c48352a6ca1   9 seconds ago   145MB
httpd            latest    ac826143758d   9 days ago      145MB

## dockerfile 생성
$ cat Dockerfile
FROM httpd
COPY index.html /usr/local/apache2/htdocs

# docker_practice에 dockerfile, index.html 확인
$ ll
total 16
-rw-r--r--  1 jingni  staff    53B  7  2 19:40 Dockerfile
-rw-r--r--@ 1 jingni  staff   142B  7  2 18:38 index.html

# docker image build
$ docker build -t ex22_original2 /Users/jingni/docs/TIL/Container/Docker/docker_practice
[+] Building 0.2s (7/7) FINISHED                                                                                                    
=> [internal] load build definition from Dockerfile                                                                           0.0s
=> => transferring dockerfile: 95B                                                                                            0.0s
=> [internal] load .dockerignore                                                                                              0.0s
=> => transferring context: 2B                                                                                                0.0s
=> [internal] load metadata for docker.io/library/httpd:latest                                                                0.0s
=> [internal] load build context                                                                                              0.0s
=> => transferring context: 228B                                                                                              0.0s
=> [1/2] FROM docker.io/library/httpd                                                                                         0.1s
=> [2/2] COPY index.html /usr/local/apache2/htdocs                                                                            0.0s
=> exporting to image                                                                                                         0.0s
=> => exporting layers                                                                                                        0.0s
=> => writing image sha256:f336853d8e6cfd0785d002cc386e0f1ebf58695fda7bd8254029167bf3803a77                                   0.0s
=> => naming to docker.io/library/ex22_original2                                                                              0.0s

# docker image 생성 확인
$ docker image ls
REPOSITORY       TAG       IMAGE ID       CREATED         SIZE
ex22_original2   latest    f336853d8e6c   5 seconds ago   145MB
ex22_original1   latest    5c48352a6ca1   4 minutes ago   145MB
httpd            latest    ac826143758d   9 days ago      145MB

```

### 도커 이미지 옮기는 방법
- 컨테이너는 먼저 이미지로 변환하지 않으면 옮기거나 복사할 수 없지만, 이미지 또한 이미지 상태 그대로는 호스트 영역으로 복새할 수 없다.
- 이 경우 도커 레지스트리를 이용하거나 `docker save` 커멘드를 통해 tar 포맷으로 생성한 후 호스트 영역으로 옮길 수 있다.
- 다시 도커 엔진으로 가져올 경우 `docker load` 커맨드를 사용하면 된다. 

<br>

## 📍 컨테이너 개조
- 컨테이너를 개조하는 방법에는 파일 복사와 마운트를 이용한 방법도 있지만, 리눅스 명령어를 컨테이너에서 실행하는 방법도 있다.
- 도커 명령어 끝에 `/bin/bash`를 추가하면 bash shell에서 명령어를 실행할 수 있다.
- bash shell을 통해 컨테이너 내부를 조작하는 동안에는 도커 명령을 사용할 수 없으며, `exit` 명령어를 통해 컨테이너로 돌아가야 한다.
- 도커와 컨테이너는 별개의 존재이므로 리눅스의 배포판 종류에 따라 사용하는 명령어의 스타일이 달라질 수 있다. 
  즉, 컨테이너 안에 있는 "운영체제 비슷한 것"의 종류가 무엇이냐에 따라 컨테이너 내부에서 사용하는 명령어가 달라지게 된다.
- 도커에서는 공식적으로 데비안 계열의 리눅스 배포판을 사용하는 것을 권장하고 있다.

<br>

## 📍 도커 허브 로그인
- 도커 레지스트리 (Docker Registry)
  - 도커 이미지를 배포하는 장소
  
- 도커 허브 (Dockerhub)
  - 도커 제작사에서 운영하는 공식 도커 레지스트리
  
- 레지스트리 (Registry)
  - 이미지를 배포하는 장소
  
- 리포지토리 (Repository)
  - 레지스트리를 구성하는 단위
  
- 이미지 이름과 태그
  - 태그 "레지스트리_주소/리포지토리_이름:버전" 형식
  - 버전을 따로 관리하기 위해 주로 태그를 사용한다.
  
  ```shell
  # 이미지에 태그 부여
  $ docker tag [원래_이미지_이름] [레지스트리_주소/리포지토리_이름:버전]
  
  # 레지스트리에 업로드
  $ docker push [레지스트리_주소/리포지토리_이름:버전]
  ```
<br>

### 💎 Reference
- [https://devlog-wjdrbs96.tistory.com/296](https://devlog-wjdrbs96.tistory.com/296)
