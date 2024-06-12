# QT5 Sample Projects

This project uses Qt 5.12.10 and is set up for both native builds on an x86_64 machine and cross-compilation for the RZ/G2L platform.

## Project Structure

```
|------ build-*                               # Build folder
|------ notepad                               # Source code
|------ packages                              # Ship packages to board
```

## Importing the Project into Qt Creator

1. **Open Qt Creator.**
2. **Import the Project:**
   - Go to `File` -> `Open File or Project`.
   - Navigate to the `project` directory and select `<project>.pro`.
   - Click `Open`.
3. **Configure the Project:**
   - Choose the desired build configuration:
     - For native build: `Desktop_Qt_5_12_10_GCC_64bit-Debug`.
     - For cross-compilation: `RZ_G2L_Qt_5_12_10-Debug`.
   - Click `Configure Project`.

## Building the Project

### Native Build (x86_64)

1. Open the project in Qt Creator.
2. Select the build configuration: `Desktop_Qt_5_12_10_GCC_64bit-Debug`.
3. Build the project (Ctrl+B).

### Cross-Compile for RZ/G2L

1. Set up the cross-compilation environment for the RZ/G2L platform.
2. Open the project in Qt Creator.
3. Select the build configuration: `RZ_G2L_Qt_5_12_10-Debug`.
4. Build the project (Ctrl+B).

## Running the Application
### Cross-Compile for RZ/G2L

1. Copy the ship packages to the board. You can use SCP or any other method to transfer the files:

```
scp -r packages root@<board_ip>:/path/to/destination
```
2. SSH into the board and navigate to `/path/to/destination/packages`.
```
ssh root@<board_ip>
cd /path/to/destination/packages
```
3. Run the executable
```
./<execution_file>
```
