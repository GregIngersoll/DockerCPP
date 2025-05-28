# DockerCPP
Repository for Docker-based C++ Project

Prerequisites:
1. Alloy installed locally.
2. Docker installed locally.
3. g++ installed locally.

Prometheus, grafana, and loki will all be within docker containers.
Alloy can be configured as a docker container, but that requires exposing the 12345 port to the host.  That is out of scope.

It is easiest for this to set up alloy as a system service, putting the alloy.service file
in the /lib/systemd/system directory.
This is usually set up on alloy install, but this repository includes a sample config.alloy.

Usage:
Build & Run executable:
1. Compile test.cpp
2. Run a.out >> <logfile_name>.  The ideal spot for <logfile_name> is in a /tmp subdirectory to reduce permission issues.

Scraping log files:
1. Edit Alloy config.yml to ensure <logfile_name> is identified as the scraping source.
2. Copy config.yml to /etc/alloy/config
3. Start alloy service:  > systemctl start alloy
4. User docker to start local grafana, prometheus, and loki:  docker compose docker-compose.yml
5. Reload alloy to pick up any changes:  > curl -X POST http://localhost:12345/-/reload
6. Reload alloy service (if not working correctly):  > systemctl reload alloy

Web endpoints:
1. http://localhost:12345 -- Alloy UI, showing the various stages of alloy.  This is good to debug any configuration issues.
2. http://localhost:3000/explore -- Grafana UI.  Selecting loki at the source allows Grafana to display logs scraped.
