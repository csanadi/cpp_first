# ── 1. fázis: fordítás ──────────────────────────────────────────
FROM gcc:13 AS builder

WORKDIR /src
COPY q.cpp ./
RUN g++ -std=c++17 -O2 -Wall -o q q.cpp

# ── 2. fázis: futtatás (csak a bináris) ─────────────────────────
FROM debian:bookworm-slim

WORKDIR /app
COPY --from=builder /src/q ./q

CMD ["./q"]
