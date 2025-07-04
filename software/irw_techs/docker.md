Docker
=
## What is?
- To fix *It works on my side?*

## 요약
- Docker는 애플리케이션을 실행하기 위한 환경을 '컨테이너'로 감싼다.
    - 실행 환경(코드 + 설정 + 라이브러리)을 통째로 담음
    - 어디서 실행하든 동일한 결과
    - 빠르고 가볍고 이식 가능

## Docker vs VM
| 항목     | Virtual Machine (VM) | Docker (Container)  |
| ------ | -------------------- | ------------------- |
| 가상화 방식 | 하드웨어 전체 가상화          | OS 위에서 프로세스 격리      |
| 속도     | 무거움, 느림              | 가볍고 빠름              |
| 실행 환경  | OS + App             | App만 실행             |
| 사용 용도  | 완전한 가상 OS 필요 시       | 특정 앱이나 서비스 실행       |
| 예시     | Windows VM, Linux VM | Node.js 앱, DB 서버 실행 |

## 구성요소
1. `Dockerfile`
    - 컨테이너를 만드는 레시피
    - 어떤 OS, 패키지, 설정 등을 사용할지 작성

2. `Image`
    - Dockerfile로 만든 스냅샷 (정적인 실행 환경)
    - 실행 전 상태 저장

3. `Container`
    - Image를 실행한 것 (프로세스)
    - 실제 돌아가는 앱

## Example
- Dockerfile
    ```
    FROM ubuntu:20.04

    RUN apt update && apt install -y g++

    COPY . /app
    WORKDIR /app

    RUN g++ -o main main.cpp

    CMD ["./main"]
    ```

- 실행
    ```
    # 이미지 생성
    docker build -t cpp-app .

    # 컨테이너 실행
    docker run cpp-app
    ```

## Docker 왜 쓰냐?
| 상황         | Docker 쓰면 좋은 이유            |
| ---------- | -------------------------- |
| 여러 개발자랑 협업 | 모두 같은 환경 보장                |
| 배포 자동화     | CI/CD에서 Docker 이미지 빌드 후 배포 |
| 여러 앱 버전 필요 | 컨테이너로 버전별 실행 가능            |
| 테스트 자동화    | 테스트용 DB, 서버 빠르게 띄울 수 있음    |

## 정리
- `Docker` = "앱을 실행할 수 있는 일회용, 휴대용 가상 환경"
    - 설치: `docker build`
    - 실행: `docker run`
    - 팀, 배포, CI/CD에 필수