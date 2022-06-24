## 📍 도커 엔진을 시작/종료하는 방법
- 도커 엔진은 도커 데스크톱을 설치한 경우 항상 자동으로 실행하도록 설정되어 있기 때문에 특별히 설정을 비활성화하지 않으면 컴퓨터가 부팅될 때마다 자동으로 실행된다.
- 도커 엔진은 컨테이너를 실행 중이 아니라면 컴퓨터의 리소스를 거의 차지하지 않으므로 문제가 없다.
- 하지만 도커 엔진 위에 올려져 있는 컨테이너의 경우 도커 엔진이 종료되면 같이 정지 상태가 되기 때문에 컨테이너를 복구하기 위해서는 따로 스크립트를 작성해야 한다.
=> 결론적으로 도커 엔진은 재부팅했을 경우 자동으로 실행이 가능하지만, 컨테이너는 수동으로 실행시켜야 한다.

### 리눅스에서 도커 엔진을 제어하는 명령어
```shell
# 도커 엔진 데몬 상태 확인
$ sudo systemctl status docker
# 도커 엔진 시작/중지 명령어
$ sudo systemctl start/stop docker
# 도커 엔진 데몬 사용/마사용 설정 명령어
$ sudo systemctl enable/disable docker
```

<br>

## 📍 컨테이너의 기본적인 사용 방법

### 1. 도커 명령어의 기본적인 형태

## docker [command] (option) [target] (arguments)
- 기본적으로는 docker command target 의 형태이며, option과 target에 argument가 지정되는 경우도 있다.
- command에는 상위 커멘드와 하위 커멘드가 있으며, 보통 상위 커멘드는 생략이 가능하다. (e.g. container, image 등)

### 2. 도커의 기본적인 명령어, 컨테이너의 생성/삭제/실행/정지

- $ docker version
    - docker의 버전을 확인할 수 있는 명령어
```shell
$ docker version
Client:
 Cloud integration: v1.0.25
 Version:           20.10.16
 API version:       1.41
 Go version:        go1.17.10
 Git commit:        aa7e414
 Built:             Thu May 12 09:20:34 2022
 OS/Arch:           darwin/amd64
 Context:           default
 Experimental:      true

Server: Docker Desktop 4.9.1 (81317)
 Engine:
  Version:          20.10.16
  API version:      1.41 (minimum version 1.12)
  Go version:       go1.17.10
  Git commit:       f756502
  Built:            Thu May 12 09:15:42 2022
  OS/Arch:          linux/amd64
  Experimental:     false
 containerd:
  Version:          1.6.4
  GitCommit:        212e8b6fa2f44b9c21b2798135fc6fb7c53efc16
 runc:
  Version:          1.1.1
  GitCommit:        v1.1.1-0-g52de29d
 docker-init:
  Version:          0.19.0
  GitCommit:        de40ad0
```

- $ docker run (docker container run)
    - 도커 컨테이너를 생성하고 실행하는 명령어
    - docker create, docker start, docker pull 명령어를 한꺼번에 수행할 수 있어 많이 쓰이는 명령어
    - 옵션
        - `-d` : detached mode 흔히 말하는 백그라운드 모드 
        - `-p` : 호스트와 컨테이너의 포트를 연결 (포워딩)
        - `-v` : 호스트와 컨테이너의 디렉토리를 연결 (마운트)
        - `-e` : 컨테이너 내에서 사용할 환경변수 설정
        - `--name` : 컨테이너 이름 설정
        - `--it` : -i와 -t를 동시에 사용한 것으로 터미널 입력을 위한 옵션 (컨테이너의 표준 입력과 로컬 컴퓨터의 키보드 입력을 연결)
        - `--rm` : 프로세스 종료시 컨테이너 자동 제거
```shell
$ docker run --name apa000ex1 -d httpd
Unable to find image 'httpd:latest' locally
latest: Pulling from library/httpd
b85a868b505f: Pull complete 
f05e6391d558: Pull complete 
95901502a360: Pull complete 
2ea5a609d7db: Pull complete 
3974bb700c53: Pull complete 
Digest: sha256:886f273536ebef2239ef7dc42e6486544fbace3e36e5a42735cfdc410e36d33c
Status: Downloaded newer image for httpd:latest
79309e16d3f0b3a2bb473b60e3c22b0c3ca1068bea4857f980edb68643cd03cc
```

- $ docker stop (docker container stop)
    - 컨테이너를 정지하는 명령어

```shell
$ docker stop apa000ex1
apa000ex1
```

- $ docker rm (docker container rm)
    - 컨테이너를 삭제하는 명령어
  
```shell
$ docker rm apa000ex1              
apa000ex1

$ docker ps
CONTAINER ID   IMAGE     COMMAND              CREATED         STATUS         PORTS     NAMES
```

- **⭐️ stop 이나 rm 처럼 이미 생성된 컨테이너의 이름을 지정해야 하는 커맨드는 컨테이너 ID와 생략형으로도 실행할 수 있다.**

- $ docker ps (docker container ls)
    - 실행 중인 컨테이너의 목록을 출력하는 기능
    - a 옵션을 추가하면 현재 존재하는 모든 컨테이너의 목록을 출력할 수 있다.

```shell
$ docker ps
CONTAINER ID   IMAGE     COMMAND              CREATED         STATUS         PORTS     NAMES
79309e16d3f0   httpd     "httpd-foreground"   8 seconds ago   Up 7 seconds   80/tcp    apa000ex1

$ docker ps -a
CONTAINER ID   IMAGE                    COMMAND                  CREATED          STATUS                     PORTS                NAMES
79309e16d3f0   httpd                    "httpd-foreground"       11 seconds ago   Up 10 seconds              80/tcp               apa000ex1
57dafb39dae0   docker/getting-started   "/docker-entrypoint.…"   2 weeks ago      Exited (255) 2 hours ago   0.0.0.0:80->80/tcp   frosty_mclaren
```

<br>

## 📍 컨테이너의 통신
- 웹 브라우저를 통해 컨테이너에 접근하려면 외부와 접속하기 위한 설정이 필요한데, 이때 설정하는 것이 port 번호이다.
- 컨테이너에서는 `-p` 옵션을 통해 호스트의 포트번호와 컨테이너의 포트번호를 함깨 기재한다 ex) 8080:80
- `-p (호스트의 포트 번호):(컨테이너의 포트 번호)`
- 호스트 포트 번호를 모두 같은 것으로 사용하면 어떤 컨테이너로 가야 할 요청인지 구분할 수 없기 때문에 호스트의 포트 번호는 겹치지 않게 설정해야 한다.

```shell
$ docker run --name apa000ex2 -d -p 8080:80 httpd
eac008cb937d3ce315354c2e81b4821b225d012acfc44e3df7b0de9033dfa928

$ docker ps
CONTAINER ID   IMAGE     COMMAND              CREATED         STATUS         PORTS                  NAMES
eac008cb937d   httpd     "httpd-foreground"   9 seconds ago   Up 8 seconds   0.0.0.0:8080->80/tcp   apa000ex2
```

- `http://localhost:8080` 접근해보기
![localhost_test.png](image/localhost_test.png)

```shell
# 이번에는 Container ID의 생략형으로 지워보았다.
$ docker stop ea
ea

$ docker rm ea
ea

# 정상 삭제 확인
$ docker ps
CONTAINER ID   IMAGE     COMMAND   CREATED   STATUS    PORTS     NAMES
```

<br>

## 📍 이미지 삭제

- docker rmi (docker image rm)
    - 컨테이너 이미지를 삭제하는 명령어
    - 컨테이너를 삭제해도 사용한 이미지는 남아 있으므로 따로 삭제해주어야 한다. 만약 해당 이미지로 생성한 컨테이너가 존재하는 경우 이미지를 삭제할 수 없으므로
    컨테이너 목록을 확인해 삭제하려는 이미지를 사용한 컨테이너를 먼저 종료 및 삭제한 후 이미지를 삭제해야 한다.

```shell
$ docker image ls
REPOSITORY               TAG       IMAGE ID       CREATED        SIZE
httpd                    latest    ac826143758d   40 hours ago   145MB
docker/getting-started   latest    cb90f98fd791   2 months ago   28.8MB

$ docker rmi httpd
Untagged: httpd:latest
Untagged: httpd@sha256:886f273536ebef2239ef7dc42e6486544fbace3e36e5a42735cfdc410e36d33c
Deleted: sha256:ac826143758d33ca03fe95caf6ccfbf38d3081dc8289d347f8e49bd014d6226e
Deleted: sha256:63cc38fb568fcbae546f72e10632071e34d7bd638c3bbb8f6d718f6130bc0b96
Deleted: sha256:e6723f55d04e25ec45aa1926437d16fcbe22f3b9ad15b949afe6c20138a65c59
Deleted: sha256:c1af61598e94904e8c20ed366d543937f1178958cecae808b5e9ceba69f0cfb4
Deleted: sha256:4293369540ab91aa7db0e80b1d6d88c95c517eb4f317bf4242f09ff0a066d185
Deleted: sha256:08249ce7456a1c0613eafe868aed936a284ed9f1d6144f7d2d08c514974a2af9

$ docker image ls
REPOSITORY               TAG       IMAGE ID       CREATED        SIZE
docker/getting-started   latest    cb90f98fd791   2 months ago   28.8MB
```

<br>