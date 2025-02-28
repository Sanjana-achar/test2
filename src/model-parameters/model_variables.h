/*
 * Copyright (c) 2024 EdgeImpulse Inc.
 *
 * Generated by Edge Impulse and licensed under the applicable Edge Impulse
 * Terms of Service. Community and Professional Terms of Service
 * (https://docs.edgeimpulse.com/page/terms-of-service) or Enterprise Terms of
 * Service (https://docs.edgeimpulse.com/page/enterprise-terms-of-service),
 * according to your product plan subscription (the “License”).
 *
 * This software, documentation and other associated files (collectively referred
 * to as the “Software”) is a single SDK variation generated by the Edge Impulse
 * platform and requires an active paid Edge Impulse subscription to use this
 * Software for any purpose.
 *
 * You may NOT use this Software unless you have an active Edge Impulse subscription
 * that meets the eligibility requirements for the applicable License, subject to
 * your full and continued compliance with the terms and conditions of the License,
 * including without limitation any usage restrictions under the applicable License.
 *
 * If you do not have an active Edge Impulse product plan subscription, or if use
 * of this Software exceeds the usage limitations of your Edge Impulse product plan
 * subscription, you are not permitted to use this Software and must immediately
 * delete and erase all copies of this Software within your control or possession.
 * Edge Impulse reserves all rights and remedies available to enforce its rights.
 *
 * Unless required by applicable law or agreed to in writing, the Software is
 * distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific language governing
 * permissions, disclaimers and limitations under the License.
 */

#ifndef _EI_CLASSIFIER_MODEL_VARIABLES_H_
#define _EI_CLASSIFIER_MODEL_VARIABLES_H_

#include <stdint.h>
#include "model_metadata.h"

#include "tflite-model/tflite_learn_34_compiled.h"
#include "edge-impulse-sdk/classifier/ei_model_types.h"
#include "edge-impulse-sdk/classifier/inferencing_engines/engines.h"

const char* ei_classifier_inferencing_categories[] = { "ADL", "FALL" };

uint8_t ei_dsp_config_32_axes[] = { 0, 1, 2 };
const uint32_t ei_dsp_config_32_axes_size = 3;
ei_dsp_config_imu_syntiant_t ei_dsp_config_32 = {
    32, // uint32_t blockId
    1, // int implementationVersion
    3, // int length of axes
    true, // boolean scaling
    false, // boolean scaling_raw
    true // boolean padding
};

const uint8_t ei_dsp_blocks_size = 1;
ei_model_dsp_t ei_dsp_blocks[ei_dsp_blocks_size] = {
    { // DSP block 32
        32,
        912, // output size
        &extract_imu_syntiant_features, // DSP function pointer
        (void*)&ei_dsp_config_32, // pointer to config struct
        ei_dsp_config_32_axes, // array of offsets into the input stream, one for each axis
        ei_dsp_config_32_axes_size, // number of axes
        1, // version
        nullptr, // factory function
    }
};
const ei_config_tflite_eon_graph_t ei_config_tflite_graph_34 = {
    .implementation_version = 1,
    .model_init = &tflite_learn_34_init,
    .model_invoke = &tflite_learn_34_invoke,
    .model_reset = &tflite_learn_34_reset,
    .model_input = &tflite_learn_34_input,
    .model_output = &tflite_learn_34_output,
};

const ei_learning_block_config_tflite_graph_t ei_learning_block_config_34 = {
    .implementation_version = 1,
    .classification_mode = EI_CLASSIFIER_CLASSIFICATION_MODE_CLASSIFICATION,
    .block_id = 34,
    .object_detection = 0,
    .object_detection_last_layer = EI_CLASSIFIER_LAST_LAYER_UNKNOWN,
    .output_data_tensor = 0,
    .output_labels_tensor = 1,
    .output_score_tensor = 2,
    .threshold = 0,
    .quantized = 1,
    .compiled = 1,
    .graph_config = (void*)&ei_config_tflite_graph_34
};

const uint8_t ei_learning_blocks_size = 1;
const uint32_t ei_learning_block_34_inputs[1] = { 32 };
const uint8_t ei_learning_block_34_inputs_size = 1;
const ei_learning_block_t ei_learning_blocks[ei_learning_blocks_size] = {
    {
        34,
        false,
        &run_nn_inference,
        (void*)&ei_learning_block_config_34,
        EI_CLASSIFIER_IMAGE_SCALING_NONE,
        ei_learning_block_34_inputs,
        ei_learning_block_34_inputs_size,
        2
    },
};


const ei_object_detection_nms_config_t ei_object_detection_nms = {
    0.0f, /* NMS confidence threshold */
    0.2f  /* NMS IOU threshold */
};

const ei_impulse_t impulse_533957_0 = {
    .project_id = 533957,
    .project_owner = "Sanjana Achar",
    .project_name = "Fall_Detection_tinyml",
    .impulse_id = 2,
    .impulse_name = "Impulse #2",
    .deploy_version = 13,

    .nn_input_frame_size = 912,
    .raw_sample_count = 300,
    .raw_samples_per_frame = 3,
    .dsp_input_frame_size = 300 * 3,
    .input_width = 0,
    .input_height = 0,
    .input_frames = 0,
    .interval_ms = 10,
    .frequency = 100,
    .dsp_blocks_size = ei_dsp_blocks_size,
    .dsp_blocks = ei_dsp_blocks,
    
    .object_detection_count = 0,
    .fomo_output_size = 0,

    
    .visual_ad_grid_size_x = 0,
    .visual_ad_grid_size_y = 0,
    
    .tflite_output_features_count = 2,
    .learning_blocks_size = ei_learning_blocks_size,
    .learning_blocks = ei_learning_blocks,

    .postprocessing_blocks_size = 0,
    .postprocessing_blocks = nullptr,

    .inferencing_engine = EI_CLASSIFIER_TFLITE,

    .sensor = EI_CLASSIFIER_SENSOR_ACCELEROMETER,
    .fusion_string = "accX + accY + accZ",
    .slice_size = (300/4),
    .slices_per_model_window = 4,

    .has_anomaly = EI_ANOMALY_TYPE_UNKNOWN,
    .label_count = 2,
    .categories = ei_classifier_inferencing_categories,
    .object_detection_nms = ei_object_detection_nms
};

ei_impulse_handle_t impulse_handle_533957_0 = ei_impulse_handle_t( &impulse_533957_0 );
ei_impulse_handle_t& ei_default_impulse = impulse_handle_533957_0;

#endif // _EI_CLASSIFIER_MODEL_METADATA_H_
