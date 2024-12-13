FROM debian:bookworm-slim

WORKDIR /app

RUN apt-get update && apt-get install -y python3-pip python3 python3-venv git pipx pypy3 -y && \
    pipx install bython && \
    pipx ensurepath && \
    chmod +x /workspaces/tests-with-py/run.sh

ENV FLASK_APP=tests-with-py

EXPOSE 8000

CMD ["/bin/bash", "-c", "flask run --host 0.0.0.0 --port 8000"]