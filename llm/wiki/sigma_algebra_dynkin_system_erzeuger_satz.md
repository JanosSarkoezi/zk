---
key: sigma_algebra_dynkin_system_erzeuger_satz
title: Gleichheit von erzeugter sigma-Algebra und erzeugtem Dynkin-System
type: satz
tags: [masstheorie, mengensysteme]
refs: [sigma_algebra_erzeugte_definition, dynkin_system_erzeugtes_definition, schnittstabiles_mengensystem_definition, sigma_algebra_dynkin_system_charakterisierung]
---
Sei $\mathcal{E} \subseteq 2^\Omega$ ein $\cap$-stabiles Mengensystem. Dann ist das erzeugte [[dynkin_system_erzeugtes_definition|Dynkin-System]] $\delta(\mathcal{E})$ ebenfalls $\cap$-stabil und es gilt:
$$\delta(\mathcal{E}) = \sigma(\mathcal{E})$$

--proof--
Wegen $\delta(\mathcal{E}) \subseteq \sigma(\mathcal{E})$ (da jede [[sigma_algebra_definition|$\sigma$-Algebra]] ein [[dynkin_system_erzeugtes_definition|Dynkin-System]] ist) genügt es zu zeigen, dass $\delta(\mathcal{E})$ eine $\sigma$-Algebra ist. Nach dem Charakterisierungssatz reicht hierfür der Nachweis der $\cap$-Stabilität von $\delta(\mathcal{E})$.
Man definiert für $B \in \delta(\mathcal{E})$ das System $\mathcal{D}_B := \{C \subseteq \Omega \mid C \cap B \in \delta(\mathcal{E})\}$. Man zeigt, dass $\mathcal{D}_B$ ein [[dynkin_system_erzeugtes_definition|Dynkin-System]] ist.
\begin{enumerate}[label=\arabic*.]
    \item Schritt: Für $E \in \mathcal{E}$ gilt $\mathcal{E} \subseteq \mathcal{D}_E$ (wegen $\cap$-Stabilität von $\mathcal{E}$), also $\delta(\mathcal{E}) \subseteq \mathcal{D}_E$.
    \item Schritt: Für $D \in \delta(\mathcal{E})$ folgt aus Schritt 1, dass $E \cap D \in \delta(\mathcal{E})$ für alle $E \in \mathcal{E}$, also $E \in \mathcal{D}_D$. Damit gilt $\mathcal{E} \subseteq \mathcal{D}_D$ und somit $\delta(\mathcal{E}) \subseteq \mathcal{D}_D$, was die $\cap$-Stabilität von $\delta(\mathcal{E})$ beweist.
\end{enumerate}
