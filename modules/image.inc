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
  foreach (image_style_options(FALSE) as $stylename => $style) {
    $new = image_style_path($stylename, $sample_image);
    $items['image_' . $stylename] = array(
      'title' => t('Image style, @stylename', array('@stylename' => $stylename)),
      'content' => theme('image', array('uri' => $new)),
      'group' => t('Media')
    );
  }

  return $items;
}
