<?php
/**
 * @file
 * Style Guide plugin file for the Image module.
 */

/**
 * Implements hook_styleguide().
 */
function image_styleguide() {
  $sample_image = backdrop_get_path('module', 'image') . '/images/sample.png';
  $items = array();

  // Iterate through the image styles on the site.
  foreach (image_style_options(FALSE) as $style_name => $style_label) {
    $style = image_style_load($style_name);
    $style_uri = image_style_path($style_name, $sample_image);
    $success = file_exists($style_uri) || image_style_create_derivative($style, $sample_image, $style_uri);

    if ($success) {
      image_style_remove_allowed_uri($style_uri);
      $items['image_' . $style_name] = array(
        'title' => t('Image style, @style_label', array('@style_label' => $style_label)),
        'content' => theme('image', array('uri' => $style_uri)),
        'group' => t('Media')
      );
    }
  }

  return $items;
}
