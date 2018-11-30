# Functional Programming in Scala

## Concepts
### Referential Transparency
Substitution model is simple to reason about since the effects of evaluation are puerly local and we need not mentally simulate sequences of state updates to understand a block of code. Understanding requires only *local reasoning*. We simply look at the function's definition and subsitute the arguments into its body.

Modular programs consist of components that can be understood and reused independently of the whole, such that the meaning of the whole depends only on the meaning of the components and the rules governing their composition. That is, they are *composable*.

Pure function separates the logic of computation itself from "what to do with the result" and "how to obtain its input". It's a **black box**

### Variance
in `trait List[+A]` the + in front of the type parameter A is a variance annotation that signals that A is a covariant or "positive" parameter of List. 
