## 📍 쿠버네티스 기본 사용법

### 파드 생성
```shell
## m-k8s (master node) 에서 실행
# kubectl run 명령어로 쉽게 파드 생성 가능
$ kubectl run nginx-pod --image=nginx
pod/nginx-pod created
$ kubectl get pods
NAME        READY   STATUS              RESTARTS   AGE
nginx-pod   0/1     ContainerCreating   0          8s

# kubectl create 명령어로도 파드 생성 손쉽게 가능
# run으로 생성 시 단일 파드로 생성, create deployment로 실행 시 디플로이먼트 내 파드로 생성됨.
$ kubectl create deployment dpy-nginx --image=nginx
deployment.apps/dpy-nginx created

# 위에서 정의한 dpy-nginx라는 이름을 제외한 나머지는 무작위 생성
$ kubectl get pods -o wide
NAME                       READY   STATUS    RESTARTS   AGE   IP               NODE     NOMINATED NODE   READINESS GATES
dpy-nginx-c8d778df-7f8pr   1/1     Running   0          67s   172.16.221.129   w1-k8s   <none>           <none>
nginx-pod                  1/1     Running   0          2m    172.16.132.1     w3-k8s   <none>           <none>

```

<br>

### 오브젝트
- 오브젝트 : 파드와 디플로이먼트를 개별 속성을 포함해 부르는 단위. 쿠버네티스를 사용하는 관점에서 파드와 디플로이먼트는 스펙(spec)과 상태(status) 등의 값을 가지고 있음.

![k8s_object.png](image/k8s_object.png)

> 기본 오브젝트의 종류

1. 파드(Pod)
   - 쿠버네티스에서 실행되는 최소 단위, 즉 웹 서비스를 구동하는 데 필요한 최소 단위. 
   - 독립적인 공간과 사용 가능한 IP를 가지고 있으며, 나의 파드는 1개 이상의 컨테이너를 갖고 있기 때문에 여러 기능을 묶어 하나의 목적으로 사용하기도 함.

2. 네임스페이스(Namespaces)
   - 쿠버네티스 클러스터에서 사용되는 리소스들을 구분해 관리하는 그룹.
   - 특별히 지정하지 않으면 기본으로 할당되는 default, 쿠버네티스 시스템에서 사용되는 kube-system, 
     온프레미스에서 쿠버네티스를 사용할 경우 외부에서 쿠버네티스 클러스터 내부로 접속하게 도와주는 컨테이너들이 속해 있는 metallb-system이 있다.

3. 볼륨(Volume)
   - 파드가 생성될 때 파드에서 사용할 수 있는 디렉터리를 제공합니다. 
     기본적으로 파드는 영속되는 개념이 아니라 제공되는 디렉터리도 임시로 사용합니다. 하지만 파드가 사라지더라도 저장과 보존이 가능한 디렉터리를 볼륨 오브젝트를 통해 생성하고 사용할 수 있습니다.

4. 서비스(Service)
   - 파드는 클러스터 내에서 유동적이기 때문에 접속 정보가 고정일 수 없으므로 파드 접속을 안정적으로 유지하도록 서비스를 통해 내/외부와 연결됨. 서비스는 새로 파드가 생성될 때 부여되는 새로운 IP를 기존에 제공하던 기능과 연결하는 역할 수행.
   - 쉽게 설명하면 쿠버네티스 외부에서 쿠버네티스 내부로 접속할 때 내부가 어떤 구조로 돼 있는지, 파드가 살았는지 죽었는지 신경 쓰지 않아도 이를 논리적으로 연결하는 것이 서비스.
   - 기존 인프라에서 **로드밸런서**, **게이트웨이**와 비슷한 역할.

<br>

### 디플로이먼트

![k8s_deployment.png](image/k8s_deployment.png)

- 기본 오브젝트만으로도 쿠버네티스를 사용할 수 있으나, 좀 더 효율적으로 작동하도록 기능들을 조합하고 추가해 구현한 것이 디플로이먼트(Deployment). 
- 이외에도 데몬셋(DaemonSet), 컨피그맵(ConfigMap), 레플리카셋(ReplicaSet), PV(PersistentVolume), PVC(PersistentVolumeClaim), 스테이트풀셋(StatefulSet) 등이 있음
- 쿠버네티스에서 가장 많이 쓰이는 디플로이먼트 오브젝트는 파드에 기반을 두고 있으며, 레플리카셋 오브젝트를 합쳐 놓은 형태.
- 실제로 API 서버와 컨트롤러 매니저는 단순히 파드가 생성되는 것을 감시하는 것이 아니라 디플로이먼트처럼 레플리카셋을 포함하는 오브젝트의 생성을 감시합니다.

![k8s_deployment2.png](image/k8s_deployment2.png)

```shell
## m-k8s (master node) 에서 실행
# 디플로이먼트 생성
$ kubectl create deployment dpy-hname --image=sysnet4admin/echo-hname
deployment.apps/dpy-hname created

# 생성 확인
$ kubectl get pods
NAME                        READY   STATUS    RESTARTS   AGE
dpy-hname-59778b9bb-ffnp8   1/1     Running   0          56s
dpy-nginx-c8d778df-7f8pr    1/1     Running   0          11m
nginx-pod                   1/1     Running   0          12m

# 디플로이먼트 삭제
$ kubectl delete deployment dpy-hname
deployment.apps "dpy-hname" deleted

# 삭제 확인
$ kubectl get pods
NAME                        READY   STATUS        RESTARTS   AGE
dpy-hname-59778b9bb-ffnp8   0/1     Terminating   0          61s
dpy-nginx-c8d778df-7f8pr    1/1     Running       0          11m
nginx-pod                   1/1     Running       0          12m

$ kubectl get pods
NAME                       READY   STATUS    RESTARTS   AGE
dpy-nginx-c8d778df-7f8pr   1/1     Running   0          12m
nginx-pod                  1/1     Running   0          13m

```
<br>

### 레플리카셋으로 파드 수 관리
- 예를 들어 파드를 3개 만들겠다고 레플리카셋에 선언하면 컨트롤러 매니저와 스케줄러가 워커 노드에 파드 3개를 만들도록 선언합니다. 
  그러나 레플리카셋은 **파드 수를 보장하는 기능만 제공**하기 때문에 롤링 업데이트 기능 등이 추가된 디플로이먼트를 사용해 파드 수를 관리하기를 권장함.

```shell
## m-k8s (master node) 에서 실행
# 현재 파드 수 확인
$ kubectl get pods
NAME                       READY   STATUS    RESTARTS   AGE
dpy-nginx-c8d778df-7f8pr   1/1     Running   0          146m
nginx-pod                  1/1     Running   0          147m

# scale 명령어로 replica 수 조정 (but, 디플로이먼트 오브젝트에 속하지 않아 리소스 확인 불가 에러 발생)
$ kubectl scale pod nginx-pod --replicas=3
Error from server (NotFound): the server could not find the requested resource

# deploy object로 생성된 dpy-nginx를 옵션을 사용해 파드의 수 조절
$ kubectl scale deployment dpy-nginx --replicas=3
deployment.apps/dpy-nginx scaled

# 조절된 파드 확인
$ kubectl get pods
NAME                       READY   STATUS    RESTARTS   AGE
dpy-nginx-c8d778df-5xhs5   1/1     Running   0          15s
dpy-nginx-c8d778df-7f8pr   1/1     Running   0          148m
dpy-nginx-c8d778df-jt9qh   1/1     Running   0          15s
nginx-pod                  1/1     Running   0          149m

# 자원 정리 및 확인
$ kubectl delete deployment dpy-nginx
deployment.apps "dpy-nginx" deleted

$ kubectl get pods
NAME                       READY   STATUS        RESTARTS   AGE
dpy-nginx-c8d778df-jt9qh   0/1     Terminating   0          43s
nginx-pod                  1/1     Running       0          149m

```

<br>

### 스펙을 지정해 오브젝트 생성하기
- kubectl create deployment 명령으로 디플로이먼트를 생성하긴 했지만, 1개의 파드만 만들어졌을 뿐이다.
- create에서는 replicas 옵션을 사용할 수 없고, scale은 이미 만들어진 디플로이먼트에서만 사용할 수 있다. 이런 설정을 적용하려면 필요한 내용을 파일로 작성해야 하며,
  이때 작성하는 파일을 오브젝트 스펙(spec)이라고 한다. 오브젝트 스펙은 일반적으로 `.yaml` 파일로 작성한다.

```shell
## m-k8s (master node) 에서 실행
# 디플로이먼트 생성
$ kubectl create -f ~/_Book_k8sInfra/ch3/3.2.4/echo-hname.yaml
deployment.apps/echo-hname created

# 생성 확인
$ kubectl get pods
NAME                        READY   STATUS    RESTARTS   AGE
echo-hname-7894b67f-7hzxt   1/1     Running   0          90s
echo-hname-7894b67f-8d46c   1/1     Running   0          90s
echo-hname-7894b67f-pxtjc   1/1     Running   0          90s
nginx-pod                   1/1     Running   0          153m

# 리플리카 값 변경
$ sed -i 's/replicas: 3/replicas: 6/' ~/_Book_k8sInfra/ch3/3.2.4/echo-hname.yaml

# 변경 확인
$ cat ~/_Book_k8sInfra/ch3/3.2.4/echo-hname.yaml | grep replicas
  replicas: 6
  
# 에러가 나면서 변경이 적용되지 않음.
$ kubectl create -f ~/_Book_k8sInfra/ch3/3.2.4/echo-hname.yaml
Error from server (AlreadyExists): error when creating "/root/_Book_k8sInfra/ch3/3.2.4/echo-hname.yaml": deployments.apps "echo-hname" already exists

```

<br>

### apply로 오브젝트 생성하고 관리하기
- `run`은 파드를 간단하게 생성하는 매우 편리한 방법이지만 run으로는 단일 파드만을 생성할 수 있으므로 모든 상황에 적용해 사용하기는 어렵다. 
- `create`로 디플로이먼트를 생성하면 앞에서 확인한 것처럼 파일의 변경 사항을 바로 적용할 수 없다는 단점이 있으므로, 쿠버네티스는 `apply`라는 명령어를 제공한다.

```shell
## m-k8s (master node) 에서 실행
# 이와 같이 변경 사항이 발생할 가능성이 있는 오브젝트는 처음부터 apply로 생성하는 것이 좋다.
$ kubectl apply -f ~/_Book_k8sInfra/ch3/3.2.4/echo-hname.yaml
Warning: kubectl apply should be used on resource created by either kubectl create --save-config or kubectl apply
deployment.apps/echo-hname configured

# 파드 생성 확인
$ kubectl get pods
NAME                        READY   STATUS    RESTARTS   AGE
echo-hname-7894b67f-76gjt   1/1     Running   0          7s
echo-hname-7894b67f-7hzxt   1/1     Running   0          3m44s
echo-hname-7894b67f-8d46c   1/1     Running   0          3m44s
echo-hname-7894b67f-crlr2   1/1     Running   0          7s
echo-hname-7894b67f-dsxz5   1/1     Running   0          7s
echo-hname-7894b67f-pxtjc   1/1     Running   0          3m44s
nginx-pod                   1/1     Running   0          155m

```

<br>

### 파드의 컨테이너 자동 복구 방법
- 파드의 자동 복구 기술을 셀프 힐링(Self-Healing)이라고 하는데, 제대로 작동하지 않는 컨테이너를 다시 시작하거나 교체해 파드가 정상적으로 작동하게 한다.

```shell
## m-k8s (master node) 에서 실행
# 현재 파드 확인
$ kubectl get pods -o wide
NAME                        READY   STATUS    RESTARTS   AGE     IP               NODE     NOMINATED NODE   READINESS GATES
echo-hname-7894b67f-76gjt   1/1     Running   0          61s     172.16.103.135   w2-k8s   <none>           <none>
echo-hname-7894b67f-7hzxt   1/1     Running   0          4m38s   172.16.132.3     w3-k8s   <none>           <none>
echo-hname-7894b67f-8d46c   1/1     Running   0          4m38s   172.16.103.134   w2-k8s   <none>           <none>
echo-hname-7894b67f-crlr2   1/1     Running   0          61s     172.16.221.131   w1-k8s   <none>           <none>
echo-hname-7894b67f-dsxz5   1/1     Running   0          61s     172.16.132.4     w3-k8s   <none>           <none>
echo-hname-7894b67f-pxtjc   1/1     Running   0          4m38s   172.16.221.130   w1-k8s   <none>           <none>
nginx-pod                   1/1     Running   0          156m    172.16.132.1     w3-k8s   <none>           <none>

# 파드 컨테이너의 쉘 접속 (bash shell)
$ kubectl exec -it nginx-pod -- /bin/bash
# nginx의 PID 확인
root@nginx-pod:/# cat /run/nginx.pid
1
# 프로세스 생성 시간 확인
root@nginx-pod:/# ls -l /run/nginx.pid
-rw-r--r--. 1 root root 2 Aug 12 19:07 /run/nginx.pid

## m-k8s (master node)의 탭 하나 더 실행해서 다음 명령어 실행
$ i=1; while true; do sleep 1; echo $((i++)) `curl --silent 172.16.132.1 | grep title` ; done

# nginx 프로세스 죽이기
root@nginx-pod:/# kill 1
root@nginx-pod:/# command terminated with exit code 137

```
#### 실습 결과 화면
![k8s_capture.png](image/k8s_capture.png)

<br>

### 파드의 동작 보증 기능

```shell
## m-k8s (master node) 에서 실행
# 파드 확인
$ kubectl get pods
NAME                        READY   STATUS    RESTARTS   AGE
echo-hname-7894b67f-76gjt   1/1     Running   0          10m
echo-hname-7894b67f-7hzxt   1/1     Running   0          14m
echo-hname-7894b67f-8d46c   1/1     Running   0          14m
echo-hname-7894b67f-crlr2   1/1     Running   0          10m
echo-hname-7894b67f-dsxz5   1/1     Running   0          10m
echo-hname-7894b67f-pxtjc   1/1     Running   0          14m
nginx-pod                   1/1     Running   2          165m (delete)

# 파드 삭제
$ kubectl delete pods nginx-pod
pod "nginx-pod" deleted

# 파드 확인 (nginx-pod 삭제되어 있음)
$ kubectl get pods
NAME                        READY   STATUS    RESTARTS   AGE
echo-hname-7894b67f-76gjt   1/1     Running   0          11m (delete)
echo-hname-7894b67f-7hzxt   1/1     Running   0          14m
echo-hname-7894b67f-8d46c   1/1     Running   0          14m
echo-hname-7894b67f-crlr2   1/1     Running   0          11m
echo-hname-7894b67f-dsxz5   1/1     Running   0          11m
echo-hname-7894b67f-pxtjc   1/1     Running   0          14m

# 디플로이먼트에 속한 파드 삭제
$ kubectl delete pods echo-hname-7894b67f-76gjt
pod "echo-hname-7894b67f-76gjt" deleted

# 파드 삭제 확인 (지워져있지만 새로운 파드 생성되어 상태가 유지됨)
$ kubectl get pods
NAME                        READY   STATUS    RESTARTS   AGE
echo-hname-7894b67f-7hzxt   1/1     Running   0          15m
echo-hname-7894b67f-8d46c   1/1     Running   0          15m
echo-hname-7894b67f-crlr2   1/1     Running   0          11m
echo-hname-7894b67f-dsxz5   1/1     Running   0          11m
echo-hname-7894b67f-nb6jz   1/1     Running   0          13s (new!)
echo-hname-7894b67f-pxtjc   1/1     Running   0          15m

```

<br>

### 노드 자원 보호하기
- 여러 가지 상황에서도 쿠버네티스는 파드를 안정적으로 작동하도록 관리한다. 또한, 노드는 쿠버네티스 스케줄러에서 파드를 할당받고 처리하는 역할을 수행한다.
- 노드에 문제가 생기더라도 파드의 문제를 최소화하기 위해 영향도가 적은 파드를 할당해 일정 기간 사용하면서 모니터링해야 한다.
- 파드는 모든 노드에 균등하게 파드를 할당하려고 하기 때문에 문제가 생길 가능성이 있는 노드라는 것을 알리기 위해 `cordon` 기능을 사용한다.

```shell
## m-k8s (master node) 에서 실행
$ kubectl apply -f ~/_Book_k8sInfra/ch3/3.2.8/echo-hname.yaml
deployment.apps/echo-hname configured

$ kubectl scale deployment echo-hname --replicas=9
deployment.apps/echo-hname scaled

$ kubectl get pods \
> -o=custom-columns=NAME:.metadata.name,IP:.status.podIP,STATUS:.status.phase,NODE:.spec.nodeName
NAME                        IP               STATUS    NODE
echo-hname-7894b67f-7hzxt   172.16.132.3     Running   w3-k8s
echo-hname-7894b67f-8d46c   172.16.103.134   Running   w2-k8s
echo-hname-7894b67f-dd96b   172.16.103.137   Running   w2-k8s
echo-hname-7894b67f-k9mmx   172.16.221.132   Running   w1-k8s
echo-hname-7894b67f-pxtjc   172.16.221.130   Running   w1-k8s
echo-hname-7894b67f-qk5vr   172.16.221.133   Running   w1-k8s
echo-hname-7894b67f-qrgfc   172.16.103.138   Running   w2-k8s
echo-hname-7894b67f-shf68   172.16.132.6     Running   w3-k8s
echo-hname-7894b67f-z2bp2   172.16.132.5     Running   w3-k8s

$ kubectl scale deployment echo-hname --replicas=3
deployment.apps/echo-hname scaled


$ kubectl get pods -o=custom-columns=NAME:.metadata.name,IP:.status.podIP,STATUS:.status.phase,NODE:.spec.nodeName
NAME                        IP               STATUS    NODE
echo-hname-7894b67f-7hzxt   172.16.132.3     Running   w3-k8s
echo-hname-7894b67f-8d46c   172.16.103.134   Running   w2-k8s
echo-hname-7894b67f-pxtjc   172.16.221.130   Running   w1-k8s

# 현재 상태를 보존하기 위해 cordon 명령어 사용
$ kubectl cordon w3-k8s
node/w3-k8s cordoned

# node에 적용되어 있는지 확인
$ kubectl get nodes
NAME     STATUS                     ROLES    AGE     VERSION
m-k8s    Ready                      master   5h2m    v1.18.4
w1-k8s   Ready                      <none>   4h58m   v1.18.4
w2-k8s   Ready                      <none>   4h54m   v1.18.4
w3-k8s   Ready,SchedulingDisabled   <none>   4h50m   v1.18.4

$ kubectl scale deployment echo-hname --replicas=9
deployment.apps/echo-hname scaled

$ kubectl get pods -o=custom-columns=NAME:.metadata.name,IP:.status.podIP,STATUS:.status.phase,NODE:.spec.nodeName
NAME                        IP               STATUS    NODE
echo-hname-7894b67f-7hzxt   172.16.132.3     Running   w3-k8s
echo-hname-7894b67f-8d46c   172.16.103.134   Running   w2-k8s
echo-hname-7894b67f-9mp9q   172.16.103.139   Running   w2-k8s
echo-hname-7894b67f-bzpf8   172.16.221.136   Running   w1-k8s
echo-hname-7894b67f-fjcs9   172.16.103.140   Running   w2-k8s
echo-hname-7894b67f-k5r2d   172.16.221.135   Running   w1-k8s
echo-hname-7894b67f-pcsbz   172.16.103.141   Running   w2-k8s
echo-hname-7894b67f-pxtjc   172.16.221.130   Running   w1-k8s
echo-hname-7894b67f-wmgdq   172.16.221.134   Running   w1-k8s

$ kubectl scale deployment echo-hname --replicas=3
deployment.apps/echo-hname scaled

$ kubectl get pods -o=custom-columns=NAME:.metadata.name,IP:.status.podIP,STATUS:.status.phase,NODE:.spec.nodeName
NAME                        IP               STATUS    NODE
echo-hname-7894b67f-7hzxt   172.16.132.3     Running   w3-k8s
echo-hname-7894b67f-8d46c   172.16.103.134   Running   w2-k8s
echo-hname-7894b67f-pxtjc   172.16.221.130   Running   w1-k8s

# uncordon 명령어로 파드가 할당되지 않도록 기능을 설정한 것을 해제함.
$ kubectl uncordon w3-k8s
node/w3-k8s uncordoned

# 다시 노드 확인
$ kubectl get nodes
NAME     STATUS   ROLES    AGE     VERSION
m-k8s    Ready    master   5h4m    v1.18.4
w1-k8s   Ready    <none>   5h1m    v1.18.4
w2-k8s   Ready    <none>   4h56m   v1.18.4
w3-k8s   Ready    <none>   4h52m   v1.18.4

```

<br>

### 노드 유지보수하기
- 정기 또는 비정기적인 유지보수를 위해 노드를 꺼야 하는 상황이 발생할 때 사용할 수 있도록 drain 기능을 제공.
- drain은 지정된 노드의 파드를 전부 다른 곳으로 이동시켜 해당 노드를 유지보수할 수 있게 한다.

```shell
## m-k8s (master node) 에서 실행
$ kubectl drain w3-k8s
node/w3-k8s cordoned
error: unable to drain node "w3-k8s", aborting command...

There are pending nodes to be drained:
 w3-k8s
error: cannot delete DaemonSet-managed Pods (use --ignore-daemonsets to ignore): kube-system/calico-node-chdrn, kube-system/kube-proxy-mjtk2

$ kubectl drain w3-k8s --ignore-daemonsets
node/w3-k8s already cordoned
WARNING: ignoring DaemonSet-managed Pods: kube-system/calico-node-chdrn, kube-system/kube-proxy-mjtk2
evicting pod default/echo-hname-7894b67f-7hzxt
pod/echo-hname-7894b67f-7hzxt evicted
node/w3-k8s evicted

# drain 명령어가 수행된 것 확인
$ kubectl get nodes
NAME     STATUS                     ROLES    AGE     VERSION
m-k8s    Ready                      master   5h5m    v1.18.4
w1-k8s   Ready                      <none>   5h2m    v1.18.4
w2-k8s   Ready                      <none>   4h58m   v1.18.4
w3-k8s   Ready,SchedulingDisabled   <none>   4h54m   v1.18.4

# drain 수행 해제 (uncordon 명령어로 가능)
$ kubectl uncordon w3-k8s
node/w3-k8s uncordoned

$ kubectl get nodes
NAME     STATUS   ROLES    AGE     VERSION
m-k8s    Ready    master   5h6m    v1.18.4
w1-k8s   Ready    <none>   5h3m    v1.18.4
w2-k8s   Ready    <none>   4h58m   v1.18.4
w3-k8s   Ready    <none>   4h54m   v1.18.4

$ kubectl delete -f ~/_Book_k8sInfra/ch3/3.2.8/echo-hname.yaml
deployment.apps "echo-hname" deleted

$ kubectl get pods
No resources found in default namespace.
```

<br>

### 파드 업데이트하고 복구하기
- 컨테이너에 새로운 기능을 추가하거나 치명적인 버그가 발생해 버전을 업데이트해야 할 때, 업데이트 도중 문제가 발생해 기존 버전으로 복구해야할 때 사용.

```shell
## m-k8s (master node) 에서 실행
# --record 옵션은 배포한 정보의 히스토리를 기록함.
$ kubectl apply -f ~/_Book_k8sInfra/ch3/3.2.10/rollout-nginx.yaml --record
deployment.apps/rollout-nginx created

# record 옵션으로 기록된 히스토리 확인 방법
$ kubectl rollout history deployment rollout-nginx
deployment.apps/rollout-nginx
REVISION  CHANGE-CAUSE
1         kubectl apply --filename=/root/_Book_k8sInfra/ch3/3.2.10/rollout-nginx.yaml --record=true

$ kubectl get pods -o=custom-columns=NAME:.metadata.name,IP:.status.podIP,STATUS:.status.phase,NODE:.spec.nodeName
NAME                             IP               STATUS    NODE
rollout-nginx-64dd56c7b5-4xm96   172.16.103.142   Running   w2-k8s
rollout-nginx-64dd56c7b5-6vqw7   172.16.221.138   Running   w1-k8s
rollout-nginx-64dd56c7b5-x8p86   172.16.132.7     Running   w3-k8s

# 헤더만 확인해 nginx 버전 정보 확인
$ curl -I --silent 172.16.103.142 | grep Server
Server: nginx/1.15.12

# nginx 버전 업데이트 진행
$ kubectl set image deployment rollout-nginx nginx=nginx:1.16.0 --record
deployment.apps/rollout-nginx image updated

$ kubectl get pods -o=custom-columns=NAME:.metadata.name,IP:.status.podIP,STATUS:.status.phase,NODE:.spec.nodeName
NAME                             IP               STATUS    NODE
rollout-nginx-64dd56c7b5-6vqw7   172.16.221.139   Running   w1-k8s
rollout-nginx-8566d57f75-94g79   172.16.132.8     Running   w3-k8s
rollout-nginx-8566d57f75-pf69k   172.16.103.143   Running   w2-k8s
rollout-nginx-8566d57f75-rb2lv   <none>           Pending   w1-k8s

# 업데이트 후 상태 확인
$ kubectl rollout status deployment rollout-nginx
deployment "rollout-nginx" successfully rolled out

$ kubectl rollout history deployment rollout-nginx
deployment.apps/rollout-nginx
REVISION  CHANGE-CAUSE
1         kubectl apply --filename=/root/_Book_k8sInfra/ch3/3.2.10/rollout-nginx.yaml --record=true
2         kubectl set image deployment rollout-nginx nginx=nginx:1.16.0 --record=true

$ curl -I --silent 172.16.132.8 | grep Server
Server: nginx/1.16.0

# 업데이트 후 상태가 이상할 경우 다시 명령 실행을 통해 전 단계로 상태를 되돌릴 수 있음.
$ kubectl rollout undo deployment rollout-nginx
deployment.apps/rollout-nginx rolled back
```

<br>

## 📍 쿠버네티스 연결을 담당하는 서비스

### 노드 포트
- 외부에서 쿠버네티스 클러스터의 내부에 접속하는 가장 쉬운 방법은 노드포트(NodePort) 서비스를 이용하는 것. 
- 노드포트 서비스를 설정하면 모든 워커 노드의 특정 포트(노드포트)를 열고 여기로 오는 모든 요청을 노드포트 서비스로 전달하고, 노드포트 서비스는 해당 업무를 처리할 수 있는 파드로 요청을 전달한다.

```shell
## m-k8s (master node) 에서 실행
$ kubectl create deployment np-pods --image=sysnet4admin/echo-hname
deployment.apps/np-pods created

$ kubectl get pods
NAME                             READY   STATUS    RESTARTS   AGE
np-pods-5767d54d4b-nq9sh         1/1     Running   0          8s
rollout-nginx-8566d57f75-94g79   1/1     Running   0          6m13s
rollout-nginx-8566d57f75-pf69k   1/1     Running   0          5m35s
rollout-nginx-8566d57f75-rb2lv   1/1     Running   0          5m3s

$ kubectl create -f ~/_Book_k8sInfra/ch3/3.3.1/nodeport.yaml
service/np-svc created

# 노드포트 지정 확인
$ kubectl get services
NAME         TYPE        CLUSTER-IP       EXTERNAL-IP   PORT(S)        AGE
kubernetes   ClusterIP   10.96.0.1        <none>        443/TCP        5h17m
np-svc       NodePort    10.100.248.191   <none>        80:30000/TCP   11s

$ kubectl get nodes -o wide
NAME     STATUS   ROLES    AGE     VERSION   INTERNAL-IP     EXTERNAL-IP   OS-IMAGE                KERNEL-VERSION                CONTAINER-RUNTIME
m-k8s    Ready    master   5h17m   v1.18.4   192.168.1.10    <none>        CentOS Linux 7 (Core)   3.10.0-1127.19.1.el7.x86_64   docker://1.13.1
w1-k8s   Ready    <none>   5h13m   v1.18.4   192.168.1.101   <none>        CentOS Linux 7 (Core)   3.10.0-1127.19.1.el7.x86_64   docker://1.13.1
w2-k8s   Ready    <none>   5h9m    v1.18.4   192.168.1.102   <none>        CentOS Linux 7 (Core)   3.10.0-1127.19.1.el7.x86_64   docker://1.13.1
w3-k8s   Ready    <none>   5h5m    v1.18.4   192.168.1.103   <none>        CentOS Linux 7 (Core)   3.10.0-1127.19.1.el7.x86_64   docker://1.13.1
```

![ip_test_capture.png](image/ip_test_capture.png)

<br>

### 인그레스
- 노드포트 서비스는 포트를 중복 사용할 수 없어서 1개의 노드포트에 1개의 디플로이먼트만 적용된다. 그러므로 여러 개의 디플로이먼트가 존재할 때는 인그레스를 사용해야 한다.
- 인그레스(Ingress)는 고유한 주소를 제공해 사용 목적에 따라 다른 응답을 제공할 수 있고, 트래픽에 대한 L4/L7 로드밸런서와 보안 인증서를 처리하는 기능을 제공한다.
- 인그레스를 사용하려면 인그레스 컨트롤러가 필요하다. 다양한 인그레스 컨트롤러가 있으므로 상황에 따라 사용하면 된다. 여기서는 쿠버네티스에서 프로젝트로 지원하는 nginx ingress controller로 구성했다. 

```shell
## m-k8s (master node) 에서 실행
$ kubectl create deployment in-hname-pod --image=sysnet4admin/echo-hname
deployment.apps/in-hname-pod created

$ kubectl create deployment in-ip-pod --image=sysnet4admin/echo-ip
deployment.apps/in-ip-pod created

$ kubectl get pods
NAME                            READY   STATUS    RESTARTS   AGE
in-hname-pod-8565c86448-xh2rn   1/1     Running   0          78s
in-ip-pod-76bf6989d-fxn8j       1/1     Running   0          41s

$ kubectl apply -f ~/_Book_k8sInfra/ch3/3.3.2/ingress-nginx.yaml
namespace/ingress-nginx created
configmap/nginx-configuration created
configmap/tcp-services created
configmap/udp-services created
serviceaccount/nginx-ingress-serviceaccount created
clusterrole.rbac.authorization.k8s.io/nginx-ingress-clusterrole created
role.rbac.authorization.k8s.io/nginx-ingress-role created
rolebinding.rbac.authorization.k8s.io/nginx-ingress-role-nisa-binding created
clusterrolebinding.rbac.authorization.k8s.io/nginx-ingress-clusterrole-nisa-binding created
deployment.apps/nginx-ingress-controller created

$ kubectl apply -f ~/_Book_k8sInfra/ch3/3.3.2/ingress-config.yaml
ingress.networking.k8s.io/ingress-nginx created

$ kubectl get pods -n ingress-nginx
NAME                                        READY   STATUS              RESTARTS   AGE
nginx-ingress-controller-5bb8fb4bb6-2h5f9   0/1     ContainerCreating   0          44s

$ kubectl get pods
NAME                            READY   STATUS    RESTARTS   AGE
in-hname-pod-8565c86448-xh2rn   1/1     Running   0          2m44s
in-ip-pod-76bf6989d-fxn8j       1/1     Running   0          2m7s

# ingress 설정 파일 등록 확인
$ kubectl get ingress
NAME            CLASS    HOSTS   ADDRESS   PORTS   AGE
ingress-nginx   <none>   *                 80      43s

$ kubectl get ingress -o yaml
apiVersion: v1
items:
- apiVersion: extensions/v1beta1
  kind: Ingress
  metadata:
...
  status:
    loadBalancer: {}
kind: List
metadata:
  resourceVersion: ""
  selfLink: ""
  
$ kubectl apply -f ~/_Book_k8sInfra/ch3/3.3.2/ingress.yaml
service/nginx-ingress-controller created

$ kubectl expose deployment in-hname-pod --name=hname-svc-default --port=80,443
service/hname-svc-default exposed

$ kubectl expose deployment in-ip-pod --name=ip-svc --port=40,443
service/ip-svc exposed

$ kubectl get services
NAME                TYPE        CLUSTER-IP       EXTERNAL-IP   PORT(S)          AGE
hname-svc-default   ClusterIP   10.109.22.142    <none>        80/TCP,443/TCP   74s
ip-svc              ClusterIP   10.111.168.222   <none>        40/TCP,443/TCP   52s
kubernetes          ClusterIP   10.96.0.1        <none>        443/TCP          5h28m

## 실습 컨테이너 정리
$ kubectl delete deployment in-hname-pod
deployment.apps "in-hname-pod" deleted

$ kubectl delete deployment in-ip-pod
deployment.apps "in-ip-pod" deleted

$ kubectl delete services hname-svc-default
service "hname-svc-default" deleted

$ kubectl delete services ip-svc
service "ip-svc" deleted
$ kubectl delete -f ~/_Book_k8sInfra/ch3/3.3.2/ingress-nginx.yaml
namespace "ingress-nginx" deleted
configmap "nginx-configuration" deleted
configmap "tcp-services" deleted
configmap "udp-services" deleted
...

$ kubectl delete -f ~/_Book_k8sInfra/ch3/3.3.2/ingress-config.yaml
ingress.networking.k8s.io "ingress-nginx" deleted

$ kubectl get pods
No resources found in default namespace.

```

![ip_test_capture2.png](image/ip_test_capture2.png)

<br>

### 로드밸런서
```shell
## m-k8s (master node) 에서 실행
$ kubectl create deployment lb-hname-pod --image=sysnet4admin/echo-hname
deployment.apps/lb-hname-pod created

$ kubectl scale deployment lb-hname-pod --replicas=3
deployment.apps/lb-hname-pod scaled

$ kubectl create deployment lb-ip-pod --image=sysnet4admin/echo-ip
deployment.apps/lb-ip-pod created

$ kubectl scale deployment lb-ip-pod --replicas=3
deployment.apps/lb-ip-pod scaled

$ kubectl get pods
NAME                            READY   STATUS    RESTARTS   AGE
lb-hname-pod-795c75578f-572mr   1/1     Running   0          2m7s
lb-hname-pod-795c75578f-5nk5r   1/1     Running   0          105s
lb-hname-pod-795c75578f-kq759   1/1     Running   0          105s
lb-ip-pod-7867cb8b9c-2dfr8      1/1     Running   0          41s
lb-ip-pod-7867cb8b9c-jdfqk      1/1     Running   0          51s
lb-ip-pod-7867cb8b9c-zv979      1/1     Running   0          41s

$ kubectl apply -f ~/_Book_k8sInfra/ch3/3.3.4/metallb.yaml
namespace/metallb-system created
podsecuritypolicy.policy/speaker created
serviceaccount/controller created
serviceaccount/speaker created
clusterrole.rbac.authorization.k8s.io/metallb-system:controller created
clusterrole.rbac.authorization.k8s.io/metallb-system:speaker created
role.rbac.authorization.k8s.io/config-watcher created
clusterrolebinding.rbac.authorization.k8s.io/metallb-system:controller created
clusterrolebinding.rbac.authorization.k8s.io/metallb-system:speaker created
rolebinding.rbac.authorization.k8s.io/config-watcher created
daemonset.apps/speaker created
deployment.apps/controller created

$ kubectl get pods -n metallb-system -o wide
NAME                          READY   STATUS              RESTARTS   AGE   IP              NODE     NOMINATED NODE   READINESS GATES
controller-5f98465b6b-94n4k   0/1     ContainerCreating   0          22s   <none>          w1-k8s   <none>           <none>
speaker-2tjfv                 0/1     ContainerCreating   0          22s   192.168.1.103   w3-k8s   <none>           <none>
speaker-n8rhk                 0/1     ContainerCreating   0          22s   192.168.1.102   w2-k8s   <none>           <none>
speaker-qqs5n                 0/1     ContainerCreating   0          22s   192.168.1.10    m-k8s    <none>           <none>
speaker-sch8m                 0/1     ContainerCreating   0          22s   192.168.1.101   w1-k8s   <none>           <none>

$ kubectl apply -f ~/_Book_k8sInfra/ch3/3.3.4/metallb-l2config.yaml
configmap/config created

$ kubectl get configmap -n metallb-system
NAME     DATA   AGE
config   1      37s

$ kubectl get configmap -n metallb-system -o yaml
apiVersion: v1
items:
- apiVersion: v1
  data:
    config: |
      address-pools:
      - name: nginx-ip-range
        protocol: layer2
        addresses:
        - 192.168.1.11-192.168.1.13
  kind: ConfigMap
  metadata:
 ...
  name: config
    namespace: metallb-system
    resourceVersion: "53313"
    selfLink: /api/v1/namespaces/metallb-system/configmaps/config
    uid: 81b0eca6-3234-465c-9721-d3f1a6c5a2d1
kind: List
metadata:
  resourceVersion: ""
  selfLink: ""

$ kubectl expose deployment lb-hname-pod --type=LoadBalancer --name=lb-hname-svc --port=80
service/lb-hname-svc exposed

$ kubectl expose deployment lb-ip-pod --type=LoadBalancer --name=lb-ip-svc --port=80      service/lb-ip-svc exposed
service/lb-ip-svc exposed

$ kubectl get services
NAME           TYPE           CLUSTER-IP       EXTERNAL-IP    PORT(S)        AGE
kubernetes     ClusterIP      10.96.0.1        <none>         443/TCP        5h47m
lb-hname-svc   LoadBalancer   10.101.110.71    192.168.1.11   80:32334/TCP   22s
lb-ip-svc      LoadBalancer   10.105.56.155    192.168.1.12   80:32645/TCP   4s

# Window Powershell에서 실행하면 로드밸런서 기능이 정상적으로 작동하는지 확인할 수 있음.
PS C:\Users\2jjin> $i=0; while($true)
>> {
>>   % { $i++; write-host -NoNewline "$i $_" }
>>   (Invoke-RestMethod "http://192.168.1.11")-replace '\n', " "
>> }

## 실습 환경 정리
$ kubectl delete deployment lb-hname-pod
deployment.apps "lb-hname-pod" deleted

$ kubectl delete deployment lb-ip-pod
deployment.apps "lb-ip-pod" deleted

$ kubectl delete service lb-hname-svc
service "lb-hname-svc" deleted

$ kubectl delete service lb-ip-svc
service "lb-ip-svc" deleted

```

<br>

### HPA (Horizontal Pod Autoscaler)
- 부하량에 따라 디플로이먼트의 파드 수를 유동적으로 관리하는 기능 제공
- 메트릭 서버(Metrics-Server)를 통해 계측값을 전달받음. 그러므로 메트릭 서버를 설정해야 HPA 사용 가능.

```shell
## m-k8s (master node) 에서 실행
$ kubectl create deployment hpa-hname-pods --image=sysnet4admin/echo-hname
deployment.apps/hpa-hname-pods created

# 로드밸런서 서비스 설정
$ kubectl expose deployment hpa-hname-pods --type=LoadBalancer --name=hpa-hname-svc --port=80
service/hpa-hname-svc exposed

# 서비스 확인
$ kubectl get services
NAME            TYPE           CLUSTER-IP      EXTERNAL-IP    PORT(S)        AGE
hpa-hname-svc   LoadBalancer   10.107.105.16   192.168.1.11   80:32699/TCP   7s
kubernetes      ClusterIP      10.96.0.1       <none>         443/TCP        5h55m

# 메트릭 서버가 없어서 생기는 오류
$ kubectl top pods
Error from server (NotFound): the server could not find the requested resource (get services http:heapster:)

# 메트릭 서버 설정
$ kubectl create -f ~/_Book_k8sInfra/ch3/3.3.5/metrics-server.yaml
clusterrole.rbac.authorization.k8s.io/system:aggregated-metrics-reader created
clusterrolebinding.rbac.authorization.k8s.io/metrics-server:system:auth-delegator created
rolebinding.rbac.authorization.k8s.io/metrics-server-auth-reader created
apiservice.apiregistration.k8s.io/v1beta1.metrics.k8s.io created
serviceaccount/metrics-server created
deployment.apps/metrics-server created
service/metrics-server created
clusterrole.rbac.authorization.k8s.io/system:metrics-server created
clusterrolebinding.rbac.authorization.k8s.io/system:metrics-server created

# 메트릭 서버 설정 후 값 확인 가능
$ kubectl top pods
NAME                              CPU(cores)   MEMORY(bytes)
hpa-hname-pods-75f874d48c-62v54   0m           1Mi
```

<br>

## 📍 알아두면 쓸모 있는 쿠버네티스 오브젝트
1. 데몬셋
   
2. 컨피그맵
   
3. PV와 PVC
   
4. 스테이트풀셋