# syntax=docker/dockerfile:1

FROM golang:1.21

# Set destination for COPY
WORKDIR /app

COPY ./ ./


# Build
RUN go build -o checker


# Run
CMD ["./checker"]