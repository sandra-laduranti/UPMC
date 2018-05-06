#Hoare Logic

```math
[p]C[q]
```
>p: Pré-condition => "**Pour tout état satisfaisant P...**"
C: Calcul => "**...si l'exécution de C se termine**"
q: Post-condition => "**...alors l'état final doit satisfaire Q**"

$$
\begin{aligned}
[x=0] \\
x:=x+1 \\
[x=1]
\end{aligned}
$$

> [x=0] -> Hypothèse (etat initial)
> [x=1] -> Prouver (etat final)

$$
\begin{aligned}
Précondition; calcul => postcondition
\end{aligned}
$$
Composition de triplets pour prouver des programmes complexes

$$
\begin{aligned}
\{Pre\} c_{0};\{P\} c;\{Q\} c_{1};\{Post\};
\end{aligned}
$$

### logic proof

$$
\begin{aligned}
\{x \ne 0 \} \\
y:=x  \times x\\
\{y = x^2 \wedge x \ne 0 \} \\
y:=y/x\\
\{y = x\} \\
\end{aligned}
$$

### Check these examples

$$
\begin{aligned}
\{x = 3\} x:=x+1 \{x \le 0\}\\
\{x = 3\} x:=x+1 \{x \ge 0\}\\
\{x = 3\} x:=x+1;y:=x \{y \ge 0\}\\
\{\exists X, x = X \wedge y = X + 1\} x:=x+1;y:=x \{x=y\}\\
\{x = 0\} \text{ if true then } x:=x+1 \text{ else } x:=x-1 \text{ fi }\{x=1\}\\
\{x = 0\} \text{ if } x=5 \text{ then } x:=x+1 \text{ else } x:=x-1 \text{ fi }\{x=1\}\\
\{x = 0\} \text{ while true do } x:=x+1 \text{ od }\{false\}\\
\end{aligned}
$$

### Hoare
