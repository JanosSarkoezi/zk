---
key: stetigkeit_gleichmaessig_definition
title: Gleichmäßige Stetigkeit
type: def
tags: [analysis, stetigkeit]
refs: [stetigkeit_epsilon_delta_definition]
---
Eine Funktion $f: X \to \mathbb{R}$ heißt auf $X$ **gleichmäßig stetig**, wenn zu jedem $\epsilon > 0$ ein $\delta > 0$ existiert, das **nur** von $\epsilon$ (und nicht von der Stelle $x$) abhängt, so dass für alle $x_1, x_2 \in X$ gilt:
$$|x_1 - x_2| < \delta \implies |f(x_1) - f(x_2)| < \epsilon$$

--proof--
Im Gegensatz zur punktweisen Stetigkeit muss das $\delta$ hier für den gesamten Definitionsbereich "gleichmäßig" funktionieren. Während bei der Stetigkeit in $\xi$ das $\delta$ von $\xi$ abhängen darf, ist die gleichmäßige Stetigkeit eine Eigenschaft der Funktion auf einer ganzen Menge.
