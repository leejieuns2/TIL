## 📌 Hypervisor (하이퍼바이저)

- 가상 머신(Virtual Machine, VM)을 생성하고 구동하는 소프트웨어
- 호스트 컴퓨터에서 다수의 운영체제를 동시에 실행하기 위한 논리적 플랫폼(Platform)
- VMM(Virtual Machine Monitor or Virtual Machine Manager) 라고도 부른다.
- 타입 1 (native or bare-metal) / 타입 2 (hosted) 로 나눈다.
    - 타입 1 : 하드웨어 위에 직접 실행되는 하이퍼바이저

      ex) VMware의 ESX Server, Xen, Citrix의 XenServer, Microsoft의 HyperV 등

    - 타입 2 : 일반 프로그램처럼 호스트 운영체제 위에 실행되는 하이퍼바이저

      ex) VMware Workstation, VMware Fusion, Oracle VirtualBox, Microsoft VirtualPC, Virtual Server 등
    
<br>

![](../image/hypervisor.png)