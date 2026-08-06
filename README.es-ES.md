

<div align="center">
<h1>HivisionlDPhoto-cpp</h1>
​



[English](README-EN.md) / Español

[![release](https://img.shields.io/badge/release-black)](https://github.com/zjkhahah/HivisionIDPhotos-cpp/releases/tag/file)
[![issue](https://img.shields.io/badge/issue-black)](https://github.com/zjkhahah/HivisionIDPhotos-cpp/issues)
[![stars](https://img.shields.io/badge/stars-green)](https://github.com/zjkhahah/HivisionIDPhotos-cpp/stargazers)
[![forks](https://img.shields.io/badge/forks-blue)](https://github.com/zjkhahah/HivisionIDPhotos-cpp/forks)




 </div>




# Índice


- [Descripción del proyecto](#项目简介)
- [Preparación](#准备工作)
- [Descarga de archivos de peso](#权重文件下载)
- [Compilación del código fuente](#源码编译)
- [Cómo utilizar](#使用)
- [Proyectos citados](#引用项目)
- [Contáctenos](#联系我们)

<br>




# Descripción del proyecto

​	**HivisionIDPhoto tiene como objetivo desarrollar un algoritmo inteligente y sistemático para la creación práctica de fotos de identificación. HivisionIDPhoto_cpp es una refactorización de HivisionIDPhoto en C++, con el propósito de aprovechar los recursos de computación de dispositivos edge, permitiendo el despliegue local en dispositivos embebidos y móviles.**

**HivisionIDPhoto_cpp puede hacer lo siguiente:**

​	**1. Despliegue móvil offline. Ejecución en dispositivos ARM.**

​	**2. Recorte de imágenes ligero (segmentación)**

​	**3. Generación de fotos de identificación estándar según diferentes especificaciones de tamaño**

​	**4. Fotos de diseño de 6 pulgadas**

​	**5. Embellecimiento facial (Beauty filter)**

​	**6. APK para Android (pendiente)**

<br>




# Preparación


La versión para Windows y la versión para Linux están empaquetadas en [release](https://github.com/zjkhahah/HivisionIDPhotos_cpp/releases/tag/file). Después de descomprimir, debe colocar el archivo ejecutable y las dependencias en el directorio raíz de HivisionIDPhotos_cpp, y los archivos de peso en la carpeta `model`.

<br>




# Descarga de archivos de peso

Guarde en el directorio `model` del proyecto

modnet_photographic_portrait_matting.mnn [Descargar](https://github.com/zjkhahah/HivisionIDPhotos-cpp/releases/tag/v1.0/modnet_photographic_portrait_matting.mnn)

hivision_modnet.mnn [Descargar](https://github.com/zjkhahah/HivisionIDPhotos-cpp/releases/tag/v1.0/mnn_hivision_modnet.mnn)

symbol_10_320_20L_5scales_v2_deploy.mnn[Descargar](https://github.com/zjkhahah/HivisionIDPhotos-cpp/releases/tag/v1.0/symbol_10_320_20L_5scales_v2_deploy.mnn)

symbol_10_320_20L_8scales_v2_deploy.mnn[Descargar](https://github.com/zjkhahah/HivisionIDPhotos-cpp/releases/tag/v1.0/symbol_10_320_20L_8scales_v2_deploy.mnn)

<br>




# Compilación del código fuente
## 	**1. Clonar el proyecto**

```
https://github.com/zjkhahah/HivisionIDPhotos_cpp.git
cd  HivisionIDPhotos_cpp
```



## 	2. Plataforma de compilación

​		**La versión de MNN es 2.9.0**

​		**La versión de OpenCV es 4.7.0**

### **1. Windows**

- Requisitos del entorno

​		Microsoft Visual Studio >= 2017

​		cmake >= 3.13

​		powershell

​		Ninja

Compile la biblioteca MNN y coloque el archivo de biblioteca estática `.a` compilado en la carpeta `lib`.

La guía de compilación para la versión de Windows de MNN está disponible en [Compilación de la biblioteca principal — MNN-Doc 2.1.1 documentation](https://mnn-docs.readthedocs.io/en/latest/compile/engine.html)

Compile la versión de Windows de OpenCV y coloque el archivo de biblioteca estática `.a` en la carpeta `lib`.

- Código de compilación

​	Encuentre `vcvars64.bat` (Comandos de herramientas nativas x64 para VS 2017) en la configuración y haga clic para abrir el entorno virtual de VS para compilar programas de arquitectura x64.

```
cd  HivisionIDPhotos_cpp
mkdir build && cd build
cmake .. -G Ninja  #命令行命令行lí, 命令行aadr el 	#命令行1	1		1		1		# 命令行, 	1	# cmake .. -G Ninja    # 1, 	1  # 	1	# 	1  # cmake .. -G Ninja -DCOMPILE_LIBRARY=ON
ninja
```

### 	**2. Compilación para ARM64**

​	Utilizaremos la cadena de herramientas Linaro como ejemplo. Primero, seleccione la cadena de herramientas adecuada desde [Linaro](https://releases.linaro.org/components/toolchain/binaries/latest-7/) según el sistema anfitrión y el dispositivo de destino de la compilación cruzada. Tomaremos `arm-linux-gnueabi` como ejemplo, haga clic en el enlace de la página para entrar en [arm-linux-gnueabi](https://releases.linaro.org/components/toolchain/binaries/latest-7/arm-linux-gnueabi/). Seleccione el enlace de descarga según el tipo de sistema anfitrión (aquí usaremos X64 Linux como ejemplo), el nombre del archivo será similar a `gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabi.tar.xz`. Descargue y descomprímalo en cualquier directorio.

​	Compile las versiones ARM64 de OpenCV y MNN.

​	La guía de compilación para la versión ARM de MNN está disponible [haciendo clic aquí](https://mnn-docs.readthedocs.io/en/latest/compile/engine.html).

Coloque los archivos estáticos de OpenCV y MNN compilados en la carpeta `lib`.

```
cd  HivisionIDPhotos_cpp
mkdir build && cd build
cmake .. \
-DCMAKE_SYSTEM_NAME=Linux \
-DCMAKE_SYSTEM_VERSION=1 \
-DCMAKE_SYSTEM_PROCESSOR=aarch64 \
-DCMAKE_C_COMPILER=/path/to/arm-linux-gnueabi-gcc \
-DCMAKE_CXX_COMPILER=/path/to/arm-linux-gnueabi-g++
make -j8
```
### <br>	**3. Compilación para Android** API

1. La guía de compilación para la versión Android de MNN está disponible en [[Compilación de la biblioteca principal — MNN-Doc 2.1.1 documentation (mnn-docs.readthedocs.io)](https://mnn-docs.readthedocs.io/en/latest/compile/engine.html)]
2. Descargue la versión de OpenCV para Android [aquí](https://github.com/opencv/opencv/releases/download/4.7.0/opencv-4.7.0-android-sdk.zip).

Coloque los archivos estáticos de OpenCV y MNN compilados en la carpeta `lib`.

````
cd  HivisionIDPhotos_cpp
mkdir build && cd build

cmake .. -DCMAKE_TOOLCHAIN_FILE=/path/to/cmake.toolchain -DCMAKE_ANDROID_NDK=/path/to/ndk -DANDROID_PLATFORM=android-21 -DANDROID_NATIVE_API_LEVEL=21 -DANDROID_ABI=arm64-v8a -DANDROID_NATIVE_API_LEVEL=21 -DCOMPILE_LIBRARY=ON -DCOMPILE_ANDROID=ON

make -j8

````





# Uso de la línea de comandos

Comandos principales:
* `-e`: Proporción de la cara en la imagen
* `-i`: Ruta de la imagen de entrada
* `-o`: Ruta de la imagen de salida
* `-k`: Tamaño de la imagen de salida
* `-f`: Selección del modelo de cara
* ...

Para más comandos, ejecute `./HivisionIDPhotos_cpp.exe --help`.

##  1. Abrir el programa
Usaremos el sistema Windows como ejemplo, utilice la herramienta powershell para navegar al directorio raíz, por ejemplo: 

` cd D:\HivisionIDPhotos-cpp`


## 2. Creación de fotos de identificación
Introduzca una foto y obtendrá una foto de identificación estándar en formato PNG.

`./HivisionIDPhotos_cpp.exe -i demo/images/test.jpg  -o 1  -r 255  -g 0  -b 0 -h 413 -w 295 `

## 3. Recorte de retratos (Segmentación)
Introduzca 1 foto y obtenga 1 imagen PNG de 4 canales con transparencia.

## 4. Generar una foto de diseño de 6 pulgadas
Introduzca una foto y obtendrá una foto de diseño de 6 pulgadas en formato PNG.

`./HivisionIDPhotos_cpp.exe -i demo/images/test.jpg  -o 1  -r 255  -g 0  -b 0 -h 413 -w 295 -l 1`

<br>




# Uso de la API

Utilice SpringBoot + JNA para llamar al archivo DLL y generar una API (en el entorno Linux se llama al archivo `.so`).
A continuación, se usa el método `human_mating` de HivisionIDPhotos como ejemplo.

## 1. Crear un proyecto SpringBoot y añadir dependencias en `pom.xml`


```
		<dependency>
            <groupId>net.java.dev.jna</groupId>
            <artifactId>jna</artifactId>
            <version>5.12.1</version>
            <scope>compile</scope>
        </dependency>
        <dependency>
            <groupId>org.projectlombok</groupId>
            <artifactId>lombok</artifactId>
            <version>1.18.8</version>
        </dependency>
        <dependency>
            <groupId>com.alibaba</groupId>
            <artifactId>fastjson</artifactId>
            <version>1.2.28</version>
        </dependency>
        <dependency>
            <groupId>commons-beanutils</groupId>
            <artifactId>commons-beanutils</artifactId>
            <version>1.9.2</version>
        </dependency>
        <dependency>
            <groupId>commons-collections</groupId>
            <artifactId>commons-collections</artifactId>
            <version>3.2.1</version>
        </dependency>
        <dependency>
            <groupId>commons-lang</groupId>
            <artifactId>commons-lang</artifactId>
            <version>2.6</version>
        </dependency>
        <dependency>
            <groupId>commons-logging</groupId>
            <artifactId>commons-logging</artifactId>
            <version>1.1.1</version>
        </dependency>
        <dependency>
            <groupId>net.sf.ezmorph</groupId>
            <artifactId>ezmorph</artifactId>
            <version>1.0.6</version>
        </dependency>
```
## 2. Colocar archivos DLL/SO

Coloque el archivo DLL que necesita llamar en `src\main\resources\win32-x86-64\`.

## 3. Construir las clases que requieren parámetros

Aquí es necesario conocer la estructura exacta de los parámetros del método y escribirlo según las reglas de mapeo de JNA. Las tres siguientes clases se escriben basándose en la estructura de parámetros de las funciones dentro de `HivisionIDphotos.dll`.

`Hivision_java_params.java`

```
public class Hivision_java_params extends Structure {
    public String model_path;
    public String image_path;
    public String out_path;
    public String face_model_path;
    public int rgb_r, rgb_g, rgb_b;
    public int thread_num, model_scale;
    public Params param = new Params();

    @Override
    protected List<String> getFieldOrder() {
        return Arrays.asList("model_path", "image_path", "out_path", "face_model_path",
                "rgb_r", "rgb_g", "rgb_b", "thread_num", "model_scale", "param");
    }
    public Hivision_java_params() {
        super();
        // 初始化默认值
        this.rgb_r = 255;
        this.rgb_g = 0;
        this.rgb_b = 0;
        this.thread_num = 4;
        this.model_scale = 8;
    }
    }
```

`Params.java`

```
public class Params extends Structure {
    public int out_image_width, out_image_height;
    public boolean change_bg_only;
    public float head_measure_ratio, head_height_ratio;
    public float[] head_top_range = new float[2];
    public int rgb_r, rgb_g, rgb_b;
    public FaceInfo face_info = new FaceInfo();

    @Override
    protected List<String> getFieldOrder() {
        return Arrays.asList("out_image_width", "out_image_height", "change_bg_only",
                "head_measure_ratio", "head_height_ratio", "head_top_range",
                "rgb_r", "rgb_g", "rgb_b", "face_info");
    }

    public Params() {
        super();
        // 初始化默认值
        out_image_width = 295;
        out_image_height = 413;
        change_bg_only = false;
        head_measure_ratio = 0.2f;
        head_height_ratio = 0.55f;
        head_top_range[0] = 0.12f;
        head_top_range[1] = 0.1f;
        rgb_r = 255;
        rgb_g = 0;
        rgb_b = 0;
    }}
```
`FaceInfo.java`
```
public class FaceInfo extends Structure {
    public float x1, y1, x2, y2, score, area;
    public float[] landmarks = new float[10];

    @Override
    protected List<String> getFieldOrder() {
        return Arrays.asList("x1", "y1", "x2", "y2", "score", "area", "landmarks");
    }

    public FaceInfo() {
        super();
        // 初始化数组
        Arrays.fill(landmarks, 0.0f);
    }}
```

## 4. Escribir la interfaz Library correspondiente

Una interfaz `Library` corresponde a un DLL, y sus métodos abstractos se corresponden uno a uno con las funciones del DLL. El primer parámetro de `Native.loadLibrary()` es la ruta del archivo DLL, sin la extensión `.dll`.

`HivisionIDphotosLibrary.java`
```
public interface HivisionIDphotosLibrary extends Library {
    HivisionIDphotosLibrary INSTANCE = Native.loadLibrary("src\\main\\resources\\win32-x86-64\\HivisionIDphotos", HivisionIDphotosLibrary.class);
    void human_mating(Hivision_java_params hivision_java_params);
    int ID_photo(Hivision_java_params hivision_java_params,int out_size_kb,boolean layout_phot);}
```

## 5. Escribir la clase Controller

`JnaDemoController.java`
```
@RestController
@RequestMapping("/JNA")
public class JnaDemoController {
    @PostMapping("/human_mating")
    public String human_mating(@RequestParam("hivision_java_params_json") String hivision_java_params_json){
        try{
            Hivision_java_params hivision_java_params = JSONObject.parseObject(hivision_java_params_json, Hivision_java_params.class);
            HivisionIDphotosLibrary.INSTANCE.human_mating(hivision_java_params);
            return "success";
        }catch (Exception e){
            System.out.println(e.getMessage());
            return "fail";
        }
    }}

```
# Proyectos citados

1. [MNN](https://github.com/alibaba/MNN):

```
@software{Alibaba_MNN_2024,
    author = {Alibaba},
    title = {{MNN}},
    url = {https://github.com/alibaba/MNN},
    year = {2024},
    publisher = {GitHub}
}
```

2. [HivisionIDPhotos](https://github.com/Zeyi-Lin/HivisionIDPhotos)

```
@software{Zeyi-Lin_HivisionIDPhotos_2024,
    author = {Zeyi-Lin},
    title = {{HivisionIDPhotos}},
    url = {https://github.com/Zeyi-Lin/HivisionIDPhotos},
    year = {2024},
    publisher = {GitHub}
}
```

3. **[LFFD-MNN](https://github.com/SyGoing/LFFD-MNN)**

```

@software{LFFD-MNN_2024,
    author = {SyGoing},
    title = {{LFFD-MNN}},
    url = {https://github.com/SyGoing/LFFD-MNN},
    year = {2024},
    publisher = {GitHub}
}

```

<br>




# Contáctenos

Si tiene alguna pregunta, por favor abra un [issue](https://github.com/zjkhahah/HivisionIDPhotos-cpp/issues) o envíe un correo electrónico a junkangzhou@stu.xidian.edu.cn.
