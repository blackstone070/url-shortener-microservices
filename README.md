# Short.ly by Devesh 
**A High-Performance, Polyglot Microservice URL Shortener**

This isn't just a simple link shortener. It is a distributed system designed for high scale, combining the raw speed of **C++**, the flexibility of **Python**, and the low latency of **Redis**.

##  The Architecture
- **The Brain (C++)**: A high-speed microservice using the **Crow** framework for Base62 encoding.
- **The Manager (Python/FastAPI)**: Orchestrates the workflow, validates URLs, and manages the API.
- **The Persistence (PostgreSQL)**: Ensures your links never disappear.
- **The Speed Layer (Redis)**: Serves popular links from RAM in **<1ms** and tracks real-time click analytics.
- **The Box (Docker)**: One-click deployment for the entire 4-service cluster.

##  Performance (Locust Load Test)
In stress tests, this system handled **800+ requests per second** for redirects with **0% failure rate**, proving the efficiency of the Redis caching layer.

##  Business Analytics
- Real-time click tracking by **State** and **Country**.
- Device type identification (Mobile vs. Desktop).
- Live dashboard polling via JavaScript.

##  Run it in 30 Seconds
Ensure you have Docker installed, then run:
```bash
docker compose up --build
