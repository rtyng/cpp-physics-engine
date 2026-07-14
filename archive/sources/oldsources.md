## Engine Architecture and Mathematics

### [1] Eric Lengyel, *Foundations of Game Engine Development, Volume 1: Mathematics*. Terathon Software, 2016.

**Project use:** Vector, matrix, transformation, quaternion, and geometric-mathematics design for the engine's core mathematical interface.

### [2] Ian Millington, *Game Physics Engine Development*, 2nd ed. Boca Raton, FL, USA: CRC Press, 2010.

**Project use:** General physics-engine architecture, particle representation, force accumulation, numerical integration, rigid-body mechanics, collision detection, and software organization.

**Design limitation:** Millington's per-body force-generator architecture does not directly represent the coupled state evaluation required by a gravitational N-body simulation. It is being used as an architectural and educational reference rather than copied directly.