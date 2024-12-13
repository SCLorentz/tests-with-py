FROM debian:bookworm-slim

WORKDIR /app

RUN apt-get update && apt-get install -y git pipx pypy3 --no-install-recommends -y && \
    pipx install bython && \
    pipx ensurepath

ENV FLASK_APP=tests-with-py

EXPOSE 8000

CMD ["/bin/bash", "-c", "flask run --host 0.0.0.0 --port 8000"]