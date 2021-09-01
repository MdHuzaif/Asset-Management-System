<?php
include_once 'blade/view.assetSearch.blade.inc';
include_once COMMON.'class.common.inc';
?>

<link rel="stylesheet" href="./resources/css/sidebarStyle.css">

<div class="container">

    <!--Search-->
    <div class="col-md-12">
        <div class="panel panel-default myPanel">

            <div class="panel-heading myHeading">
                <strong>&nbsp;Search Asset</strong>
            </div>

            <div class="panel-body form-horizontal">

                <!--Search Form-->
                <form method="post" class="form-horizontal">

                    <!--Type-->
                    <div id="divType" class="form-group">
                        <label for="type" class="control-label col-md-3">Type :</label>
                        <div class="col-md-7">
                            <select name="type" id="type" class="form-control">
                                <option value="" selected="selected" disabled>Select Type</option>
                                <?php
                                $Result=$_AssetBao->getAllAssetType();
                                if ($Result->getIsSuccess()){
                                    $TypeList=$Result->getResultObject();
                                    foreach ($TypeList as $type){
                                        ?>
                                        <option value="<?php echo $type->getAssetTypeId(); ?>" ><?php echo $type->getAssetTypeName(); ?></option>
                                        <?php
                                    }
                                }
                                ?>
                            </select>
                        </div>
                    </div>

                    <!--Serial-->
                    <div id="divSerial" class="form-group">
                        <label for="serial" class="control-label col-md-3">Serial :</label>
                        <div class="col-md-7">
                            <input type="text" name="serial" id="serial" class="form-control" >
                        </div>
                    </div>

                    <!--Model-->
                    <div id="divModel" class="form-group">
                        <label for="model" class="control-label col-md-3">Model :</label>
                        <div class="col-md-7">
                            <input type="text" name="model" id="model" class="form-control" >
                        </div>
                    </div>

                    <!--Brand-->
                    <div id="divBrand" class="form-group">
                        <label for="brand" class="control-label col-md-3">Brand :</label>
                        <div class="col-md-7">
                            <input type="text" name="brand" id="brand" class="form-control" >
                        </div>
                    </div>

                    <!--Status-->
                    <div id="divStatus" class="form-group">
                        <label for="status" class="control-label col-md-3">Status :</label>
                        <div class="col-md-7">
                            <select name="status" id="status" class="form-control">
                                <option value="" selected="selected" disabled="disabled">Select Status</option>
                                <option value="Working" class="text-success">Working</option>
                                <option value="On Repair" class="text-warning">On Repair</option>
                                <option value="Damaged" class="text-danger">Damaged</option>
                            </select>
                        </div>
                    </div>

                    <!--Cost-->
                    <div id="divCost" class="form-group">
                        <label for="cost" class="control-label col-md-3">Cost :</label>
                        <div class="col-md-7">
                            <input type="text" name="cost" id="cost" class="form-control" >
                        </div>
                    </div>

                    <div class="form-group">
                        <input type="submit" name="searchAsset" class="btn btn-primary col-md-2 col-md-offset-5" value="Search" id="addAsset">
                    </div>

                </form>

            </div>
        </div>
    </div>
</div>

<!--Display Search Results-->
<?php
if (isset($_POST['searchAsset'])) {
    $Asset = new Asset();
    $Asset->setAssetTypeId($_DB->secureInput($_POST['type']));
    $Asset->setAssetSerialNo($_DB->secureInput($_POST['serial']));
    $Asset->setAssetModelNo($_DB->secureInput($_POST['model']));
    $Asset->setAssetBrand($_DB->secureInput($_POST['brand']));
    $Asset->setAssetStatus($_DB->secureInput($_POST['status']));
    $Asset->setAssetCost($_DB->secureInput($_POST['cost']));

    $Result = $_AssetBao->searchAsset($Asset)
    ?>
    <div class="col-md-12">
        <hr>
    </div>
    <div class="col-md-12">
        <div class="panel panel-table">
            <table class="table table-bordered table-responsive">
                <!--Header Row-->
                <tr>
                    <th>Type</th>
                    <th>Serial No</th>
                    <th>Model No</th>
                    <th>Brand</th>
                    <th>Purchase Date</th>
                    <th>Current Status</th>
                    <th>Configuration</th>
                    <th>Received By</th>
                    <th>Purchased From</th>
                    <th>Price</th>
                    <th>Warranty Limit</th>
                    <th>Edit</th>
                    <th>Delete</th>
                </tr>

                <!--Table Cells-->
                <?php
                if ($Result->getIsSuccess()) {
                    $AssetList = $Result->getResultObject();

                    foreach ($AssetList as $asset) {
                        ?>
                        <tr <?php if ($asset->getAssetStatus() == "Working") {
                            echo 'class="table-cell alert-success"';
                        } elseif ($asset->getAssetStatus() == "On Repair") {
                            echo 'class="table-cell alert-warning"';
                        } else {
                            echo 'class="table-cell alert-danger"';
                        }
                        ?>>
                            <td><?php echo $_AssetBao->getTypeById($asset->getAssetTypeId())->getResultObject()->getAssetTypeName(); ?></td>
                            <td><a href="asset_details.php?serialNo=<?php echo $asset->getAssetSerialNo(); ?>"
                                   class="table-a"><?php echo $asset->getAssetSerialNo(); ?></a></td>
                            <td><?php echo $asset->getAssetModelNo(); ?></td>
                            <td><?php echo $asset->getAssetBrand(); ?></td>
                            <td><?php echo $asset->getAssetPurchaseDate(); ?></td>
                            <td><?php echo $asset->getAssetStatus(); ?></td>
                            <td><?php if (strlen($asset->getAssetConfiguration()) > 50) {
                                    echo substr($asset->getAssetConfiguration(), 0, 50) . '...';
                                } else {
                                    echo $asset->getAssetConfiguration();
                                } ?>
                            </td>
                            <?php
                            $StuffName = $_AssetBao->getStuffById($asset->getAssetStuffId())->getResultObject();
                            ?>
                            <td><a href="user_details.php?id=<?php echo $StuffName->getID(); ?>" class="table-a"><?php
                                    echo $StuffName->getFirstName() . ' ' . $StuffName->getLastName();
                                    ?></a></td>

                            <td><?php echo $asset->getAssetPurchasedFrom(); ?></td>

                            <td><?php echo $asset->getAssetCost(); ?></td>

                            <td><?php echo $asset->getAssetWarrantyLimit(); ?></td>

                            <td><a href="asset.php?edit=<?php echo $asset->getAssetId(); ?>"
                                   onclick="return confirm('sure to edit !!');">edit</a></td>

                            <td><a href="asset.php?del=<?php echo $asset->getAssetId(); ?>"
                                   class="span-danger"
                                   onclick="return confirm('sure to delete !!');">delete</a></td>
                        </tr>
                        <?php
                    }
                }
                ?>
            </table>
        </div>
    </div>
    <?php
}
?>
