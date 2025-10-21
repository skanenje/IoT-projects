# IoT-projects — Practical, simulatable projects to master IoT engineering

This repository is a hands-on learning workspace designed to help engineers master end-to-end IoT system design by building small, simulatable projects. The focus is on embedded-side communication and control logic, device networking protocols (MQTT, HTTP, I²C, SPI, Serial), and designing reliable, power-aware data flows from sensor → edge → cloud.

Each project is intentionally small, well-documented, and runnable in simulation (Wokwi, PlatformIO) before moving to hardware. The exercises pair low-level embedded code (C/C++ for microcontrollers) with higher-level tooling and scripts in Go, Rust, or Python to practice integration, testing, and repeatable deployment patterns.

## Goals

- Build a first-principles understanding of IoT communication (MQTT, HTTP) and embedded bus protocols (I²C, SPI, Serial).
- Implement robust embedded-side control and telemetry logic with careful attention to power and reliability.
- Use simulation to iterate quickly and validate sensor–edge–cloud flows before hardware deployment.
- Combine system-level thinking with software engineering skills in Go, Rust, and Python to create repeatable, testable data pipelines.

## Learning outcomes

After working through the projects you will be able to:

- Explain and implement core device networking protocols: MQTT (pub/sub), HTTP (REST), and direct serial/bus interactions.
- Design embedded firmware that reliably samples sensors, debounces inputs, retries transient comms, and serializes telemetry.
- Simulate device firmware and peripheral interactions using Wokwi or PlatformIO and debug flows end-to-end.
- Integrate a simulated or local MQTT broker and cloud-side consumer to validate end-to-end data delivery.
- Apply power-aware patterns (sleep cycles, duty cycling, peripheral gating) and reason about energy trade-offs.

## Repo structure

Top-level layout (projects are self-contained):

- `led-blink/` — example project demonstrating embedded build, simulation metadata and tests.
	- `platformio.ini` — PlatformIO project config.
	- `wokwi.toml` — Wokwi simulation metadata.
	- `src/` — firmware source files (`main.cpp`, `Blink.cpp`).
	- `include/` — public headers.
	- `test/` — unit/integration tests (PlatformIO test runner compatible).

Add new projects by following this template: include a `README.md`, `platformio.ini`, simulation metadata (`wokwi.toml` or similar), `src/`, `include/`, and `test/` directories.

## How to run and simulate

PlatformIO (build, test, monitor)

1. Build a project (from repo root):

```bash
pio run -d led-blink
```

2. Run unit/integration tests (PlatformIO test runner):

```bash
pio test -d led-blink
```

3. Open a serial monitor for live firmware output:

```bash
pio device monitor -d led-blink
```

Wokwi (online simulator)

- Projects that include `wokwi.toml` can be opened in the Wokwi web simulator for rapid hardware-in-the-loop verification. Use the Wokwi UI or paste the project files into a new simulation.

Simulating MQTT/Cloud flows

- Use a local broker (Mosquitto) or a cloud MQTT service to validate pub/sub flows produced by firmware. Example local test using Mosquitto:

```bash
# start mosquitto (system dependent)
mosquitto -v
# publish a test message
mosquitto_pub -t test/topic -m '{"ts": 0, "temp": 22.5}'
# subscribe to verify messages
mosquitto_sub -t test/topic
```

- Use small Python/Go/Rust consumers to emulate cloud ingestion, message validation, and storage. Keep these scripts in project subfolders (or add a `tools/` directory for cross-project utilities).

## Project conventions

- Keep each project focused and single-purpose (device driver, comms pattern, sensor flow).
- Include a short `README.md` in each project outlining what the exercise teaches, the simulation steps, and expected outputs.
- Add tests for parsing, serialization, and protocol logic where possible (tests live in each project's `test/` folder).

## Example workflow

1. Modify firmware in `led-blink/src` and rebuild with PlatformIO.
2. Run the project in Wokwi for quick peripheral checks (GPIO, timers, interrupts).
3. Use a local MQTT broker and a small Python consumer to validate telemetry formatting and QoS behavior.
4. Iterate on power-saving code paths and repeat tests to compare behavior.

## Recommended tooling

- PlatformIO — building, testing, and deploying firmware.
- Wokwi — online microcontroller/peripheral simulation.
- Mosquitto — local MQTT broker for integration tests.
- Python / Rust / Go — for cloud-side consumers, data validators, and test harnesses.

## How to contribute

- Add a new project folder following the template described above.
- Keep examples small, well-documented, and simulatable before requiring hardware.
- Add or update tests that verify protocol behavior and serialization formats.
- Open a pull request describing the learning objectives and any simulation instructions.

## Notes on power-aware design

- Prefer event-driven sampling with low-power sleep states between measurements.
- Gate peripherals (I²C, SPI) only when needed and batch sensor reads to reduce wake time.
- Test time-to-first-byte and retry backoffs in simulation to validate network reliability trade-offs.

---

If you'd like, I can:

- Add a short example consumer in Python that subscribes to a broker and validates JSON payloads.
- Add `CONTRIBUTING.md` and a project template generator script to make adding new exercises easier.

Happy hacking — use simulation aggressively, and move to hardware only after the data flow and edge logic are validated.

