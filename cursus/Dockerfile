FROM debian:bookworm 
WORKDIR /root
RUN apt update
RUN apt upgrade -y
RUN apt install git -y
RUN git clone https://github.com/xicodomingues/francinette.git
RUN apt install curl -y
RUN apt install gcc -y
RUN apt install clang -y
RUN apt install valgrind -y
RUN apt install software-properties-common -y
RUN apt install python3.11-minimal -y
RUN echo "alias python=python3.11" >> ~/.bashrc
RUN export PATH=${PATH}:/usr/bin/python3.11
RUN /bin/bash -c "source ~/.bashrc"
RUN apt install python3-pip -y
RUN apt install python3.11-venv -y
RUN python3 -m venv /venv
ENV PATH="/venv/bin:$PATH"
RUN pip install --upgrade pip setuptools
RUN python3 -m pip install --upgrade pip setuptools
RUN python3 -m pip install norminette
RUN bash /root/francinette/bin/install.sh
WORKDIR /root/app
CMD ["bash", "/root/francinette/tester.sh"]
