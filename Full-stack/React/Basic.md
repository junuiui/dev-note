Basic
===

## JSX
- 자바스크립트 안에서 `HTML` 문법을 쓸 수 있게 해주는 문법
- React에서 화면 구성할 때, 이걸 사용해서 `UI` 를 표현
```jsx
function Hello() {
    return <h1>Hello, React!!!<h1>;
}

// 위 코드는 HTML처럼 보이지만 실제로는 아래처럼 변환
React.createElement('h1', null, 'Hello, React!!!');
```
- 즉, `JSX`는 `HTML`과 비슷하게 생긴 JS 문법이고, `React`가 이걸 JS 객체 형태로 바꿔서 Rendering

## Component
- `UI`를 구성하는 가장 작은 단위
- `React` 앱은 여러 개의 `Component`로 이루어져 있음.
- 각 Component는 **독립적으로 관리되고 재사용**될 수 있어.
```jsx
function Button() {
    return <button>Click me</button>
}
```
- 다른 Component 안에서도 사용 할 수 있음
```jsx
function App() {
  return (
    <div>
      <h1>My App</h1>
      <Button />   {/* Reuse */}
      <Button />
    </div>
  );
}
```
- Summary
    - UI를 나누는 Block 단위
    - 함수로 만들며, 반드시 대문자로 시작
    - 재사용 가능
    - 독립적
    - 입력 (props) => 출력 (UI) 구조

## Props (Properties)
- Component에 전달하는 Data
- 부모 Component -> 자식 Component로 값을 전달할 때 사용
```jsx
function Greeting({ name }) {
  return <p>Hello, {name}!</p>;
}

function App() {
  return (
    <>
      <Greeting name="Jun" />
      <Greeting name="Alice" />
    </>
  );
}
// Greeting Component는 name이라는 props를 받아서 출력
```
- 즉, props는 함수의 매개변수처럼 작동
- **Summary**
    - Parent -> Child 로 데이터 전달
    - 읽기 전용 (변경 불가)
    - `{ }` 안에 넣어야함. `<Comp propName={value} />`

## Promise (js 비동기 처리 객체)
- Async 작업의 결과를 나타내는 객체
    - Ex) Server에서 Data를 불러올 때 시간이 걸리니까 결과가 나중에 (resolve) 오도록 약속하는 개념
```js
const promise = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve("Data received!");
  }, 2000);
});

promise.then((result) => {
  console.log(result); // 2초 뒤 "Data received!"
});
```
- **Summary**
    - 시간이 걸리는 작업(예: API 요청)을 처리할 때 사용
    - 3가지 상태가 있음:
        - `pending` (대기 중)
        - `fulfilled` (성공)
        - `rejected` (실패)
    - `.then()`, `.catch()` 로 결과 처리
    - `async` / `await` 문법으로 더 깔끔하게 사용 가능
```js
async function fetchData() {
  const res = await fetch('https://api.example.com/data');
  const data = await res.json();
  console.log(data);
}
```