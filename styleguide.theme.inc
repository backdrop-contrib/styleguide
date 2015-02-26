<?php
/**
 * @file
 * Theme functions for Style Guide module.
 */

/**
 * Theme the page header.
 *
 * @param $variables
 *   The theme variables array, including:
 *   -- 'theme_info' an array of information about the current theme.
 */
function theme_styleguide_header($variables) {
  $theme_info = $variables['theme_info'];

  $output = '<h2>' . t('Showing style guide for %theme', array('%theme' => $theme_info['name'])) . '</h2>';
  if (isset($theme_info['description'])) {
    $output .= '<p>' . $theme_info['description'] . '</p>';
  }

  return $output;
}

/**
 * Theme a display item.
 *
 * @param $variables
 *   The theme variables array, including:
 *   -- 'key' a unique string indicating the name of the item.
 *   -- 'item' an array of data about the item.
 *   -- 'content' the content to display for this item.
 *
 * @see hook_styleguide()
 */

function theme_styleguide_item($variables) {
  $key = $variables['key'];
  $item = $variables['item'];
  $content = $variables['content'];

  $output  = "<a name=\"$key\"></a>";
  $output .= '<h2 class="styleguide">'. $item['title'] .'</h2>';
  if (!empty($item['description'])) {
    $output .= '<p class="styleguide-description">';
    $output .= $item['description'];
    $output .= '</p>';
  }
  $output .= '<div class="styleguide">';
  $output .= $content;
  $output .= '</div>';

  return $output;
}

/**
 * Theme the page links.
 *
 * NOTE: these may be turned into sub-tabs.
 *
 * @param $variables
 *   The theme variables array, including:
 *   -- 'items' the list of links.
 */
function theme_styleguide_links($variables) {
  $output  = '<div id="styleguide-header" class="styleguide clearfix">';
  $output .= $variables['items'];
  $output .= '</div>';

  return $output;
}

/**
 * Theme the content.
 *
 * This function is here in case anyone wants to change it.
 *
 * @param $variables
 *   The theme variables array, including:
 *   -- 'content' an HTML content element.
 */
function theme_styleguide_content($variables) {
  return $variables['content'];
}
