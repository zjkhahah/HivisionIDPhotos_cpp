#pragma once
#include "main.h"



#define NMS_UNION 1
#define NMS_MIN  2

typedef struct FaceInfo {
	float x1;
	float y1;
	float x2;
	float y2;
	float score;
	float area;

	float landmarks[10];
}FaceInfo;


typedef struct Params {
	int out_image_width = 295;
	int out_image_height = 413;
	bool change_bg_only = false;
	float head_measure_ratio = 0.2;
	float head_height_ratio = 0.55;
	float head_top_range[2] = { 0.12f, 0.1f };
	int rgb_r = 255;
	int rgb_b = 0;
	int rgb_g = 0;
	FaceInfo face_info;

}Params;

class LFFD {
public:
	LFFD(const std::string& model_path, int scale_num = 5, int num_thread_ = 4);
	~LFFD();

	int detect(cv::Mat& img, std::vector<FaceInfo>& face_lis, int resize_h = 480, int resize_w = 640,
		float score_threshold = 0.6, float nms_threshold = 0.4, int top_k = 10000,
		std::vector<int> skip_scale_branch_list = {});

private:
	void generateBBox(std::vector<FaceInfo>& collection, MNN::Tensor* score_map, MNN::Tensor* box_map, float score_threshold,
		int fea_w, int fea_h, int cols, int rows, int scale_id);
	void get_topk_bbox(std::vector<FaceInfo>& input, std::vector<FaceInfo>& output, int topk);
	void nms(std::vector<FaceInfo>& input, std::vector<FaceInfo>& output,
		float threshold, int type = NMS_MIN);
private:
	std::shared_ptr<MNN::Interpreter> lffd;
	MNN::Session* sess_lffd = nullptr;

	MNN::Tensor* input_tensor = nullptr;
	std::vector< MNN::Tensor*> outputTensors;
	MNN::CV::ImageProcess::Config img_config;


	int num_thread;
	int num_output_scales;
	int image_w;
	int image_h;

	std::string mnn_model_file;

	std::vector<float> receptive_field_list;
	std::vector<float> receptive_field_stride;
	std::vector<float> bbox_small_list;
	std::vector<float> bbox_large_list;
	std::vector<float> receptive_field_center_start;
	std::vector<float> constant;

	std::vector<std::string> output_blob_names;

};
