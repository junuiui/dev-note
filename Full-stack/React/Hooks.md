$$ Hooks $$

## What is "HOOK"?
- A Hook is a special function in React that lets you use features like state, lifecycle, and context inside functional components.
  
## State Management
- `useState()`
  - good for capturing use input
  - used to *show* or *hide* components
- `useReducer()`
  - for more complex state management
  - good if you have a lot of related state
```jsx
const reducer = (state, action) => {
    switch(action){
        case 'increment':
            return state + 1;
        case 'decrement':
            return state - 1;
    }
}

const [count, dispatch] = useReducer(reducer, 0)
<button onClick = {() => dispatch('increment')}> + </button>
```

## Ref
- NOT trigger re-render
- mutable (can modify directly)

## Effect 
- used to perform side effects in `React`
    > let you synchronize with a system outside `React`
```jsx
const [count, setCount] = useState();

useEffect( () => {
    document.title = `you clicked ${count} times`
}, [count])

<button onClick={() => setCount(prev => prev + 1)}> + </button>
```
- Types of Effect
  - Event-Based (button click)
  - Render-Based (fetching data)

## Performance
- `useMemo()`
  - uses memoization
  - not for side effects
  - must return a value
- `useCallback()`
  - for functions
  - prevents re-render 

## Context
- `useContext()`
```jsx
const ThemeContext = createContext()
function App() {
    return (
        <ThemeContext.Provider value="dark">
            <Form />
        </ThemeContext.Provider >
    )
}

function Form() {
    const theme = useContext(ThemeContext)
    // ...
}
```

## Random
- useId()
  - creates unique ids
  - best for id prop on form fields



