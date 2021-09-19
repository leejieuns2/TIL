## 📌 VMware

### 데스크톱 관련 소프트웨어

1. **VMware WorkStation**
    - VMware WorkStation Pro (유료) / VMware WorkStation Player (무료)
   - 데스크톱 성능 및 디버깅에 특화되어 있는 개인용 하이퍼바이저 소프트웨어
   
2. **VMware Fusion**
   - VMware WorkStation의 MacOS ver.
   - VMware Fusion Pro (유료) / VMware Fusion Player (무료)
   - MacOS를 게스트 운영체제로 사용할 수 있으며, Workstation에서는 MacOS 가상화 지원 불가.
   
3. **VMware Horizon View**
   - VDI(Virtual Desktop Infra) 제품 중 하나.
   - vSphere와 기타 관리 서버를 기반으로 시스템 운영자에게는 가상화 데스크톱의 일괄 배포 및 중앙 관리 기능을, 시스템 사용자에게는 배포된 가상화 데스크톱에 접근하여 사용할 수 있는 기능을 제공하는 제품

<br>

### 서버 관련 소프트웨어

1. **VMware vSphere ESXi**
    - Server용 엔터프라이즈 하이퍼바이저 소프트웨어
    - Bare-metal Server (물리적 서버)상에서 작동하며, VM을 여러개 생성하게 되면 물리적 서버 1개를 여러 개의 논리적 서버로 파티셔닝 할 수 있음. 다른 OS가 필요하지 않음.
    - ESXi는 무료 vSphere Hypervisor 혹은 유료 vSphere Edition의 일부로 제공되고 있음.
    - VM당 최대 128개의 가상 CPU와 최대 4TB의 RAM을 사용할 수 있음.

2. **VMware vCenter**
    - 서버 관리 소프트웨어
    - 단일 콘솔을 통해 하이브리드 클라우드 전반에 가시성과 확장성 및 효율적인 관리 제공
    - VMware vSphere 환경을 위한 중앙 집중식 관리 플랫폼 제공
    - RESTful API를 사용하여 쉽게 기능 제어 가능.

3. **VMware vSAN**
    - Flash에 최적화된 vSphere Native Storage
    - VMware Tanzu와의 통합 사용을 통한 애플리케이션의 손쉬운 관리 가능.

4. **VMware NSX**
    - 네트워크 및 보안 가상화 플랫폼
    - 가상 클라우드 네트워크 사용 가능. 자동화된 프로비저닝 제공.

5. **VMware Tanzu**
    - 애플리케이션 및 인프라의 현대화를 지원하는 소프트웨어
    - Kubernetes 클러스터의 중앙 집중식 라이프사이클 및 정책 관리를 지원

<br>

### 클라우드 관련 소프트웨어

1. **VMware Cloud Foundation**
    - 멀티 클라우드 관리 솔루션
    - VM, Kubernetes 및 컨테이너에 대한 통합 지원 제공
    
2. **VMware vRealize Suite**
    - 하이브리드 클라우드 관리 플랫폼
    - 애플리케이션, 인프라 및 플랫폼 서비스의 배포 및 운영을 손쉽게 할 수 있도록 지원.