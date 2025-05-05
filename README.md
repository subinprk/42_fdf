# 🧊 fdf — 3D Wireframe Renderer in C

A 42-school project to render 3D landscapes in isometric projection using only lines (wireframes). Built in C with no external graphics libraries other than [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx), this project was also my personal playground for applying **linear algebra** concepts in pure C.

![Result Screenshot](https://github.com/user-attachments/assets/6543e9b6-68c1-4545-8e5f-c9582af505ea)

## 🧠 Project Overview

- Parse `.fdf` files that represent elevation maps
- Convert grid points into 3D vectors
- Apply rotation, projection, and scaling transformations manually
- Render the result using MiniLibX in an X11 window
- Exit gracefully via `ESC` key or window cross button

---

## ✨ Features

- Custom implementation of 3D rotation matrices
- Isometric projection using manual projection matrix
- Mouse-independent navigation
- Window rendering with real-time responsiveness
- Manual memory management (no leaks, norm-compliant)

---

## 🔍 Implementation Details

Instead of using high-level abstractions, I implemented all the math logic from scratch to deeply understand how rendering pipelines work.

### 📐 Rotation Matrix

```c
void make_angle(float a, float b, float c, float (*angle)[3][3])

//Constructs a 3D rotation matrix using Euler angles (a, b, c).
//📦 Projection Matrix

void project(float ***array)

//Projects 3D points onto 2D plane using a custom orthographic projection matrix.
//📏 Distance and Scaling

void make_distanced(float ***array, int x, int y)

//Applies rotation
// Projects to 2D
//Normalizes and scales to fit the screen
```
🛠️ Tech Stack
* Tool	Description
* C	Core language
* MiniLibX	Simple X11-based graphics library
* Makefile	Build system (norm-compliant)
* libft	Utility functions for parsing and math
* math.h	Used for sin/cos functions in matrix calculations
### 📂 Usage

### 🔧 Compile
```
make
```
🚀 Run
```
./fdf maps/42.fdf
```
 You can create your own .fdf maps — just write space-separated elevation integers.

📚 Learning Outcome

* Practiced linear algebra directly in C: matrix multiplication, projections, scaling
* Understood the math behind isometric rendering
* Managed dynamic memory for 3D structures manually
* Built an appreciation for how rendering pipelines work under the hood
* Reinforced clean, testable modular design while staying compliant with strict C norms

📸 Preview
![Screenshot from 2025-05-05 17-34-32](https://github.com/user-attachments/assets/d75f9818-c628-4957-a76c-d79c55ae11f3)


![Screenshot from 2025-05-05 17-35-13](https://github.com/user-attachments/assets/c884c6d1-2534-4e59-9f26-8a3cdd1dc0c2)

🔮 Future Ideas

While I didn’t implement the bonus features, here are some things I'd consider adding later:

    ⬆️ Zoom in/out
    ↕️ Pan / Translate
    🔄 Real-time rotation via keyboard
    🌈 Color mapping by elevation

📄 License

This project is part of the 42 School curriculum and is licensed for educational and personal use.
🤝 Acknowledgements

Thanks to 42 and the open-source MiniLibX for helping me explore low-level graphics programming and linear algebra in one of the most hands-on ways possible.


