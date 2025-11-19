$$ React $$

## Components
- all the visible parts of the app
  - buttons / inputs / even entire pages
- resuable
- `JavaScript` function that returns `markup` in HTML
    ```js
    // js function
    function fn() { }

    // markup
    function SweetButton() {
        return <button>Click me</button>
    }
    ```
    - but in `React`, it returns `JSX`

## Curly Braces
- accept values like strings and numbers directly, use them to make attribute dynamic, style react elements using js object
- return one thing, one parent element component

## Fragments

## Props
- To pass data
  
## Children
- passed `Components`
    ```js
    function Parent(props) {
        return <div>{props.children}</div>
    }
    ```
    - good for layout components

## Keys
- used for react can tell one component apart from another.
- unique string or number

## Rendering
- Virtual DOM (VDOM)
    > DOM = Document Object Model
- state changes? => diffs => Reconciliation (update the changes)

## State
- snpashot from a camera, picture of the app at any given time to manage State we also can't use JS variables, since it does not cause the app to rerender
- `useState()`
- `useReducer()`

## Controlled Components
```js
function ControlledInput() {
    const [value, setValue] = useState('')

    return (
        <input 
        value={value} 
        onChange={(e) => setValue(e.target.value)} 
        />
    )
}
```
- Steps
  1. user types, setValue called
  2. state updated
  3. input reads from state

## Hooks
- allow us to hook into features such as state within function components
- 5 types of Hooks
  1. State hooks - `useState()` / `useReducer()`
    - manage state
  2. Context hooks - `useContext()`
    - use data passed through context
  3. Ref hooks - `useRef()`
    - 'reference' things like HTML element
  4. Effect Hooks - `useEffect()`
    - connect with external systems like browser API
  5. Performance - `useMemo()` / `useCallback()`
    - Imporve app performance (preventing unnecessary work)
    - 
<br>check out [details](./Hooks.md) for more info

## Purity
- how React components should work
  - Same input ALWAYS return the same output
    - only return JSX
    - don't change stuff that existed before rendering

## Strict Mode
- special components which tells about mistakes as we develop our react app.

## Effects
- used when need to talk with the browser API or make a request to a server. Need a way to step out side of react (EFFECT!!!)
- code that reaches outside of React app
    ```js
    // event handler
    function handleSubmit(e) {
        e.preventDefault()
        // Reqeust (side effect) made in event handler
        post('/api/register', {email, password});
    }

    // useEffect - if side effect can't be run in event handlers
    useEffect( () => {
        fetchData().then(data => {
            // use data here
        }, [])
        // fetches data when componet loads
        }
    )
    ```

## Refs
- work directly with the DOM
- to get access on any react element

## Context
- powerful way to pass prop data through apps components
- if layers are in mutiple level, passing down props, need to add multiple props. 
  - to avoid, use context to jump to where the data needs to go
  ```jsx
  // 1. Create your context (parent)
  const AppContext = createContext();

  // 2. Wrap Provider component
  <AppContext.Provider>
    <App />
  </ AppContext.Provider>

  // 3. put data on value prop
  <AppContext.Provider value="hi">

  // 4. get data with useContext
  function Title() {
    const text = useContext(AppContext)
    return <h1>{text}</h1>
  }
  ```

## Portals
- kind of like `context` but for components
- let move react components into any HTML element you select
- good for
  - displaying modals, drop-down menus, tooltips
    ```jsx
    <div>
        <p>I'm in the parent div.</p>
        {createPortal( // use function
            // pass component
            <p>I'm in the document body</p> 
            document.body // pick HTML element where it should go
        )}
    </div>
    ```

## Suspenses
- component to wait for something to load (loading)
- when it takes some time, fall back to a component until it loads

<br>
<br>

[source-youtube-link](https://www.youtube.com/watch?v=wIyHSOugGGw)