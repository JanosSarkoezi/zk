---
key: stetigkeit_gleichmaessig_definition
title: Gleichmäßige Stetigkeit
type: def
tags: [analysis, stetigkeit]
refs: [stetigkeit_epsilon_delta_definition]
---
Eine Funktion $f: X \to \mathbb{R}$ heißt auf $X$ **gleichmäßig [[stetigkeit_epsilon_delta_definition|stetig]]**, wenn zu jedem $\epsilon > 0$ ein $\delta > 0$ existiert, das **nur** von $\epsilon$ (und nicht von der Stelle $x$) abhängt, so dass für alle $x_1, x_2 \in X$ gilt:
$$|x_1 - x_2| < \delta \implies |f(x_1) - f(x_2)| < \epsilon$$

--examples--
Im Gegensatz zur punktweisen [[stetigkeit_epsilon_delta_definition|Stetigkeit]] muss das $\delta$ hier für den gesamten Definitionsbereich "gleichmäßig" funktionieren. Während bei [[stetigkeit_epsilon_delta_definition|der Stetigkeit]] in $\xi$ das $\delta$ von $\xi$ abhängen darf, ist die gleichmäßige [[stetigkeit_epsilon_delta_definition|Stetigkeit]] eine Eigenschaft der Funktion auf einer ganzen Menge.
