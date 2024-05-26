# Use the STIGed Red Hat Iron Bank base image
FROM registry1.dso.mil/ironbank/redhat/ubi8/ubi-minimal:latest

# Install necessary packages
RUN microdnf install -y cmake gcc gcc-c++ make && microdnf clean all

# Create a user for VS Code
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# Set the user
USER $USERNAME

# Set the working directory
WORKDIR /workspace