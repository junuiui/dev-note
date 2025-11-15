HTML
===

## What is HTML?
- for the Webpage

## Block vs Inline
- 블록(block): 한 줄 전체 차지 — `<div>, <p>, <h1>`
- 인라인(inline): 내용만큼 차지 — `<span>, <a>, <strong>`

## DOM (Document Object Model)
- 브라우저가 HTML 문서를 Object 형태로 변환한 구조

```css
Document
 └── html
      ├── head
      │     ├── meta
      │     └── title
      └── body
            ├── h1
            └── button
```
- 이런 Tree 구조로 만든것

### Virtual DOM
- 실제 DOM을 자바스크립트 객체로 가볍게 복사해 놓은 가짜 DOM
- DOM 직접수정은 Heavy 함.
- In `react`, 
    - 상태가 변함 → 화면 수정 필요
    - Virtual DOM에서 먼저 변경 사항 계산
    - 이전 화면과 비교(diff)
    - 바뀐 부분만 실제 DOM에 업데이트
    ```css
    [이전 Virtual DOM]  ← diff →  [새 Virtual DOM]
                ↓
     바뀐 부분만 실제 DOM에 반영
    ```

- For example)
```
기존 방식:
    집 안에서 바로 가구를 옮기며 시도
    → 힘들고 시간이 많이 걸림

Virtual DOM 방식:
    먼저 종이나 앱에서 레이아웃 시뮬레이션
    → 확정된 부분만 실제로 옮김
    → 훨씬 빠르고 효율적
```